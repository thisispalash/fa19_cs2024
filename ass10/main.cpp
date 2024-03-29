/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 10, 2019
 *
 */

/* To run
 $ clang -lstdc++ -std=c++11 -o ass10.out MenuCommand.cpp Menu.cpp BankAccount.cpp Bank.cpp main.cpp
 $ ./ass10.out
 */

#include "MenuCommandH.h"
#include "MenuH.h"
#include "BankH.h"

int main(int argc, char* argv[]) {
  /* common lambdas */
  std::function<bool()> exit = []() { return 0; };
  std::function<int(bool)> getAmt = [](bool dep) { 
    std::cout << "enter amount to " << ((dep)? "deposit":"withdraw") << ": ";
    int amt; std::cin >> amt;
    return amt;
  };
  Bank b;
  Item *acc[] = { // Sub menu
    new Command("balance inquiry",'1',[&]() { 
      std::cout << "Account Balance: " << std::to_string(b.getCurrent()->getBalance());
      std::cout << std::endl;
      return 1; }),
    new Command("deposit funds",'2',[&]() { 
      std::cout << "Account Balance: " << std::to_string(b.getCurrent()->deposit(getAmt(1))); 
      std::cout << std::endl;
      return 1; }),
    new Command("withdraw $$$$",'3',[&]() {
      int res = b.getCurrent()->withdraw(getAmt(0));
      std::cout << ((res!=-1)? "Account Balance: "+std::to_string(res) : "insufficient funds");
      std::cout << std::endl;
      return 1; }),
    new Command("go back",'b',exit)
  };
  Item *top[] = { // Main menu
    new Command("list accounts",'1',[&]() { b.lstAcc(); return 1; }),
    new Command("new account",'2',[&]() { b.newAcc(); return 1; }),
    new Command("select account",'3',[&]() {
      b.lstAcc(); std::cout<<"enter account num: ";
      int num; std::cin>>num;
      b.accDet(b.setCurrent(num)); // Display the details of the selected account
      return 1; }),
    new Command("current account",'4',[&]() { b.accDet(b.getCurrent()); return 1; }),
    new Menu(acc, sizeof(acc)/sizeof(acc[0]),"account menu",'5'),
    new Command("quit",'q',exit)
  };
  Menu top_menu(top, sizeof(top)/sizeof(top[0]), "main menu", 'm');
  top_menu.select(); // No use of the bool returned
  std::cout << "bye\n";
  return 0;
}