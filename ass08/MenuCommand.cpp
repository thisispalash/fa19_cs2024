/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 29, 2019
 *
 */

#include "MenuCommandH.h"

/* Overloaded Operators */

ostream& operator<< (ostream &os, Item &i) {
  os << " ";
  os << i.x;
  os << ". ";
  os << i.title;
  os << "\n";
  return os;
}

/* Abstract Base Class `Item` */

bool Item::select() {

}

void Item::display() {

}

/* Derived Class `Command` */

Command::Item(std::string title, char x) {
  this->title = title;
  this->x = x;
}