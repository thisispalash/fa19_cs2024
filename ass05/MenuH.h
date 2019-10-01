/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */

#include <iostream>
using namespace std;

enum ItemCode { NEW, LIST, QUIT, UNKNOWN };

class Menu {
  public:
    void showMenu();
    ItemCode promptUser();
};