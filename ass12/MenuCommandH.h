/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include <functional>

#include "MenuItemH.h"

#ifndef MENU_COMMAND
#define MENU_COMMAND

class Command: public Item {
  private: std::function<bool()> _fun_ptr;
  public: 
    Command(std::string, char, const std::function<bool()>&);
    bool execute();
    bool select();
    void display();
};

#endif /* MENU_COMMAND */