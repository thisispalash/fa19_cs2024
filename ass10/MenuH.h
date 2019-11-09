/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 2, 2019
 *
 */

#ifndef MENUITEM_H
#define MENUITEM_H
  #include "MenuItemH.h"
#endif

class Menu: public Item {
  private: std::vector<Item *> items;
  public: 
    Menu(Item* [], int, std::string, char);
    bool select();
    void display();
};