/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 9, 2019
 *
 */

#ifndef MENUITEM_H
#define MENUITEM_H
#include "MenuItemH.h"
#include <functional>
#endif

class Command: public Item {
  private: std::function<bool()> fun_ptr;
  public: 
    Command(std::string, char, const std::function<bool()>&);
    bool execute();
    bool select();
    void display();
};