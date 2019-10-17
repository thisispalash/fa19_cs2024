/*  
 *  CS 2024 ass07
 *  Author: Palash A. [pa334]
 *  Date: October 17, 2019
 *
 */

/* To run
 $ clang -lstdc++ -o ass07 MenuItem.cpp Menu.cpp main.cpp
 $ ./ass07
 */


#include <iostream>
#include "MenuH.h"


/* Overloaded operators */

ostream& operator<< (ostream &os, Item &i) {
  os << " ";
  os << i.x;
  os << ". ";
  os << i.title;
  os << "\n";
  return os;
}

ostream& operator<< (ostream &os, Menu &m) {
  os << "\n----- Menu -----\n";
  for(int i=0; i<m.items.size(); i++)
    os << m.items[i];
  os << "----------------\n";
  return os;
}

/* Menu Functions */

void printName() {
  cout << "Who am i?" << endl;
}

void square() {
  int n;
  cout << "Enter number to be squared: ";
  cin >> n;
  cout << "Square of " << n << " = " << n*n << endl;
}

/* Start of Execution */

int main(int argc, char* argv[]) {
  Item items[] = {
    Item("Print  Name",'1'),
    Item("Square  num",'2'),
    Item("Quit   asap",'3')
  }; // Menu Items
  Menu menu(items,sizeof(items)/sizeof(items[0]));
    // `sizeof(arr)/sizeof(arr[0])` divides total size by size of one element.
  char x;
  do {
    cout << menu << endl;
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