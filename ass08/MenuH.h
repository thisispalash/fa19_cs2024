/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 29, 2019
 *
 */


#include "MenuItemH.h"
#include <vector>

class Menu: public Item {
  private: std::vector<Item> items*;
  friend ostream& operator<< (ostream& os, Menu &m);
  public:
    Menu(Item[], int, char, std::string);
    char promptUser();
};