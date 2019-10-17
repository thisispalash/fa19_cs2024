/*  
 *  CS 2024 ass07
 *  Author: Palash A. [pa334]
 *  Date: October 17, 2019
 *
 */

#include "MenuItemH.h"

Item::Item(string title, char x) {
  this->title = title;
  this->x = x;
}

char Item::getPrompt() { return this->x; }

