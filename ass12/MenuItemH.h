/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include <iostream>

#ifndef MENU_ITEM
#define MENU_ITEM

class Item {
public:
  Item(std::string t, char x) : _title(t), _x(x) {}
  virtual bool select() = 0;
  virtual void display() = 0;
  char getPrompt() { return _x; }
protected:
  char _x;
  std::string _title;
};

#endif /* MENU_ITEM */