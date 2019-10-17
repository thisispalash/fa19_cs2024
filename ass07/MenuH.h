/*  
 *  CS 2024 ass07
 *  Author: Palash A. [pa334]
 *  Date: October 17, 2019
 *
 */

#include "MenuItemH.h"
#include <vector>

class Menu {
  private: vector<Item> items;
  public:
    Menu(Item[], int);
    char promptUser();
  friend ostream& operator<< (ostream& os, Menu &m);
};