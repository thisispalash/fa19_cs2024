/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 30, 2019
 *
 */

/* To run
 $ clang -lstdc++ -o ass08 MenuCommand.cpp Menu.cpp main.cpp
 $ ./ass08
 */

#include "MenuH.h"
#include "MenuCommandH.h"

int main(int argc, char* argv[]) {
  Item *acc[] = { // Sub menu for account actions
    new Command("balance inquiry",'1'),
    new Command("deposit funds",'2'),
    new Command("withdraw $$$$",'3'),
    new Command("go back",'b')
  };
  Item *top[] = {
    new Command("list accounts",'1'),
    new Command("new account",'2'),
    new Menu(acc, 4,"account menu",'3'),
    new Command("quit",'q')
  };
  Menu top_menu(top, 4, "main menu", 'm'); // the character should not matter as this is not to be displayed as an option anywhere
  top_menu.select(); // The last false returned on quitting does not matter
  std::cout << "bye\n";
  return 0;
}