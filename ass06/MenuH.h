/*  
 *  CS 2024 ass06
 *  Author: Palash A. [pa334]
 *  Date: October 12, 2019
 *
 */

#include "MenuItemH.h"
#include <vector>

class Menu {
  private: vector<Item> items;
  public:
    Menu(Item[], int);
    void showMenu(); 
    char promptUser();
};