/*  
 *  CS 2024 ass03
 *  Author: Palash A. [pa334]
 *  Date: September 18, 2019
 *
 */

#include "menu.h"
#include <iostream>

using namespace std;

class Menu {
  public:
  void showMenu() {
    cout << "--- Menu ---" << endl;
    cout << "1. Print my name 3 times" << endl;
    cout << "2. Square a number" << endl;
    cout << "3. Quit" << endl;
    cout << "--- ---- ---" << endl;
  }
  ItemCode promptUser() {
    int c;
    cout << "Please enter your choice: ";
    cin >> c;
    switch(c) {
      case 1: return PRINT;
      case 2: return SQUARE;
      case 3: return QUIT;
    }
    return UNKNOWN; // Could put this in default as well, but functions the same
  }
};