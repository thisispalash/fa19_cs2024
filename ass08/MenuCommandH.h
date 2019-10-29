/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 29, 2019
 *
 */

#include "MenuItemH.h"

class Command: public Item {
  private:
    std::string title;
    char x;
  friend ostream& operator<< (ostream& os, Item &i);
  public:
    Item(std::string,char);
};