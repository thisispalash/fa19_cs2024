/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Nov 29, 2019
 *
 */

/* To run
 $ clang -lstdc++ -std=c++11 -o ass12.out MenuCommand.cpp Menu.cpp BankAccount.cpp Bank.cpp main.cpp
 $ ./ass12.out
 */

#include <iostream>

#include "MenuCommandH.h"
#include "MenuH.h"
#include "BankH.h"

int main(int argc, char* argv[]) {
  Bank b; // One instance to rule them all

  /* common lambdas */
  std::function<bool()> exit = []() { return 0; };
  std::function<int(bool)> getDepAmt = [](bool dep) { 
    std::cout << "enter amount to " << ((dep)? "deposit":"withdraw") << ": ";
    int amt; std::cin >> amt; return amt;
  };
  Item *acc[] = { // Sub menu
    new Command("balance inquiry",'1',[&]() { 
      if (!b.getCurrent()) { std::cout << "No account selected.\n"; return 0; }
      std::cout << "Account Balance: " << std::to_string(b.getCurrent()->getBalance());
      std::cout << std::endl;
      return 1; }),
    new Command("deposit funds",'2',[&]() { 
      if (!b.getCurrent()) { std::cout << "No account selected.\n"; return 0; }
      std::cout << "Account Balance: " << std::to_string(b.getCurrent()->getBalance()) << "$";
      int new_bal = b.getCurrent()->deposit(getDepAmt(true));
      std::cout << "Updated Balance: " << std::to_string(new_bal) << "$" << std::endl;
      return 1; }),
    new Command("withdraw $$$",'3',[&]() {
      if (!b.getCurrent()) { std::cout << "No account selected.\n"; return 0; }
      std::cout << "Account Balance: " << std::to_string(b.getCurrent()->getBalance()) << "$";
      int res = b.getCurrent()->withdraw(getDepAmt(false));
      std::cout << ((res!=-1)? "Updated Balance: "+std::to_string(res)+"$" : "insufficient funds");
      std::cout << std::endl; return 1; }),
    new Command("transfer $$$",'4',[&]() {
      if (!b.getCurrent()) { std::cout << "No account selected.\n"; return 0; }
      b.lstAcc(); std::cout << "Account number to transfer to: ";
      int to; do { std::cin >> to;
        if (!b.getAcc(to)) std::cout << "Invalid account number. Please try again: ";
        else if(to == b.getCurrent()->getBalance()) std::cout << "You cannot send money to yourself! Try again: "
        else break;
      } while(1); std::cout << "Amount to transfer: ";
      int amt; std::cin >> amt;
      struct Txn txn = b.transaction_do(b.getCurrent(),b.getAcc(to),amt);
      std::cout << "Updated Balance: " << std::to_string(b.getCurrent()->getBalance()) << "$"; 
      return 1;
    }),
    new Command("go back",'b',exit)
  };
  Item *top[] = { // Main menu
    new Command("list accounts",'1',[&]() { b.lstAcc(); return 1; }),
    new Command("new account",'2',[&]() { b.newAcc(); return 1; }),
    new Command("select account",'3',[&]() {
      b.lstAcc(); std::cout<<"enter account num: ";
      int num; std::cin>>num; b.setCurrent(num); b.accDet(); return 1; }),
    new Command("current account",'4',[&]() { b.accDet(); return 1; }),
    new Menu(acc, sizeof(acc)/sizeof(acc[0]),"account menu",'5'),
    new Command("quit",'q',exit)
  };
  Menu top_menu(top, sizeof(top)/sizeof(top[0]), "main menu", 'm');
  top_menu.select(); // No use of the bool returned
  std::cout << "goodbye.\n\n";
  return 0;
}