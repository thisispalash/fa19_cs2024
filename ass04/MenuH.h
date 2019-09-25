/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 25, 2019
 *
 */

#include <iostream>
using namespace std;

enum ItemCode { INQUIRY, SET, DEPOSIT, WITHDRAW, QUIT, UNKNOWN };

class Menu {
  public:
    void showMenu();
    ItemCode promptUser();
};