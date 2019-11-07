/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 2, 2019
 *
 */

/* To run
 $ clang -lstdc++ -o ass09 MenuCommand.cpp Menu.cpp BankAccount.cpp Bank.cpp main.cpp
 $ ./ass08
 */

#include "MenuH.h"
#include "BankH.h"
#include "MenuCommandH.h"

int main(int argc, char* argv[]) {
  Bank b; BankAccount ba;
  Item *acc[] = {
    new Command("balance inquiry",'1',ba.getBalance),
    new Command("deposit funds",'2',ba.deposit),
    new Command("withdraw $$$$",'3',ba.withdraw),
    new Command("go back",'b')
  };
  Item *top[] = {
    new Command("list accounts",'1',b.lstAcc),
    new Command("new account",'2',b.newAcc),
    new Menu(acc, 4,"account menu",'3'),
    new Command("quit",'q')
  };
  Menu top_menu(top, 4, "main menu", 'm'); // Prompt for top level menu not selected explicitly
  top_menu.select(); // Currently, no use of the boolean returned by top level select
  std::cout << "bye\n";
  return 0;
}