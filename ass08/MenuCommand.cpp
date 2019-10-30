/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 30, 2019
 *
 */

#include "MenuCommandH.h"

Item::Item(std::string t, char x) {
  this->title = t;
  this->x = x;
}

bool Command::select() {
  if(this->x == 'q' || this->x == 'b')
    return 0;
  std::cout << this->title << " selected\n";
  std::cout << "---------------\n";
  return 1;
}

void Command::display() {
  std::cout << this->x << ". " << this->title << std::endl;
}

Command::Command(std::string title, char x) : Item(title, x) {
  // this->title = title;
  // this->x = x;
}