/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include <vector>

#include "MenuItemH.h"
#ifndef MENU_H
#define MENU_H

class Menu: public Item {
  private: std::vector<Item *> _items;
  public: 
    Menu(Item* [], int, std::string, char);
    bool select();
    void display();
};

#endif /* MENU_H */