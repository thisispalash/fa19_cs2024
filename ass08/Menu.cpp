/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 29, 2019
 *
 */

#include "MenuH.h"

/* Overloaded Operators */

ostream& operator<< (ostream &os, Menu &m) {
  os << "\n----- Menu -----\n";
  for(int i=0; i<m.items.size(); i++)
    os << m.items[i];
  os << "----------------\n";
  return os;
}

/* Abstract Base Class `Item` */

bool Item::select() {

}

void Item::display() {

}

/* Derived Class `Menu` */

Menu::Menu(Item items[], int len) {
  for(int i=0; i<len; i++)
    this->items.push_back(items[i]); // one statement bodies do not need braces
}

char Menu::promptUser() {
  char x;
  std::cout << "Please enter your choice: ";
  std::cin >> x;
  for(int i=0; i<this->items.size(); i++) {
    if(x == this->items[i].getPrompt())
      return x; // one statement bodies do not need braces
  }
  return '\0';
}