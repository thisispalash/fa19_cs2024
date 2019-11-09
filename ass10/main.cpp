/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 9, 2019
 *
 */

/* To run
 $ clang -lstdc++ -std=c++11 -o ass09 MenuCommand.cpp Menu.cpp BankAccount.cpp Bank.cpp main.cpp
 $ ./ass09
 */

#include "MenuH.h"
#include "BankH.h"
#include "MenuCommandH.h"

int main(int argc, char* argv[]) {
  std::function<bool()> exit = []() -> bool{ return 0; };
  Item *acc[] = {
    new Command("balance inquiry",'1',NULL),
    new Command("deposit funds",'2',NULL),
    new Command("withdraw $$$$",'3',NULL),
    new Command("go back",'b',exit)
  }; Bank b;
  Item *top[] = {
    new Command("list accounts",'1',[&]() { b.lstAcc(); return 1; }),
    new Command("new account",'2',[&]() { b.newAcc(); return 1; }),
    new Menu(acc, 4,"account menu",'3'),
    new Command("quit",'q',exit)
  };
  Menu top_menu(top, 4, "main menu", 'm'); // Prompt for top level menu not selected explicitly
  top_menu.select(); // Currently, no use of the boolean returned by top level select
  std::cout << "bye\n";
  return 0;
}