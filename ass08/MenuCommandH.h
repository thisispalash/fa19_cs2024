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

class Command: public Item {
  public: 
    Command(std::string, char);
    bool select();
    void display();
};