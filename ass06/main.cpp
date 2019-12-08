/*  
 *  CS 2024 ass06
 *  Author: Palash A. [pa334]
 *  Date: October 12, 2019
 *
 */

/* To run
 $ clang -lstdc++ -o ass06.out MenuItem.cpp Menu.cpp main.cpp
 $ ./ass06.out
 */


#include <iostream>
#include "MenuH.h"

void printName() {
  cout << "Who am i?" << endl;
}

void square() {
  int n;
  cout << "Enter number to be squared: ";
  cin >> n;
  cout << "Square of " << n << " = " << n*n << endl;
}

int main(int argc, char* argv[]) {
  Item items[] = {
    Item("Print Name",'1'),
    Item("Square num",'2'),
    Item("Quit  asap",'3')
  };
  Menu menu(items,sizeof(items)/sizeof(items[0])); char x;
  do {
    menu.showMenu();
    x = menu.promptUser();
    switch(x) {
      case '1': printName(); 
        break;
      case '2': square(); 
        break;
      case '3': cout << "goodbye." << endl; 
        break;
      default: cout << "Unknown choice, please try again." << endl; 
    }
  } while(x != '3'); // Exits the loop when the user wants to quit
  return 0;
}