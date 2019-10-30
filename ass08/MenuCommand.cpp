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
} // I wonder if this can be moved to MenuItemH
Command::Command(std::string title, char x) : Item(title, x) {}

bool Command::select() {
  if(this->x == 'q' || this->x == 'b')
    return 0; // stop displaying current menu
  std::cout << this->title << " selected\n"; // command functionality
  std::cout << "--------------------\n";
  return 1; // continue displaying current menu
}

void Command::display() {
  std::cout << this->x << ". " << this->title << std::endl;
}