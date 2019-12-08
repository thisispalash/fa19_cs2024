/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include "MenuCommandH.h"

Command::Command(std::string title, char x, 
  const std::function<bool()> &ptr) : Item(title,x) {
    _fun_ptr = ptr;
}

bool Command::select() {
  if(_fun_ptr == nullptr) {
    std::cout << "unimplemented\n";
    return 1;
  }
  return _fun_ptr();
}

void Command::display() {
  std::cout << _x << ". " << _title << std::endl;
}