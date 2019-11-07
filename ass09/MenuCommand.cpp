/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 2, 2019
 *
 */

#include "MenuCommandH.h"

Item::Item(std::string t, char x) {
  this->title = t;
  this->x = x;
} // I wonder if this can be moved to MenuItemH

Command::Command(std::string title, char x) : Item(title, x) {
  this->ptr = this->execute;
}

bool Command::select() {
  if(this->x == 'q' || this->x == 'b')
    return 0; // stop displaying current menu
  if(this->ptr != '\0')
    return this->ptr();
  return 1; // continue displaying the current menu if all fail
}

void Command::display() {
  std::cout << this->x << ". " << this->title << std::endl;
}