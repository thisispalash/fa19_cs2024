/*  
 *  CS 2024 ass10
 *  Author: Palash A. [pa334]
 *  Date: Nov 10, 2019
 *
 */

#include "MenuCommandH.h"

Item::Item(std::string t, char x) {
  this->title = t;
  this->x = x;
} // I wonder if this can be moved to MenuItemH

Command::Command(std::string title, char x, 
  const std::function<bool()> &ptr) : Item(title,x) {
    this->fun_ptr = ptr;
}

bool Command::select() {
  if(this->fun_ptr == NULL) {
    std::cout << "unimplemented\n";
    return 1;
  }
  return this->fun_ptr();
}

void Command::display() {
  std::cout << this->x << ". " << this->title << std::endl;
}