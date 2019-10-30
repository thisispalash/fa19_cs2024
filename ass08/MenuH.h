/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 30, 2019
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