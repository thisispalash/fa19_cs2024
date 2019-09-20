/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 20, 2019
 *
 */

#include "menu.h"
#include <iostream>

using namespace std;

class Menu {
  public:
  void showMenu() {
    cout << endl;
    cout << "--- Menu ---" << endl;
    cout << "1. Balance Inquiry" << endl;
    cout << "2. Set Balance" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Quit" << endl;
    cout << "------------" << endl;
  }
  ItemCode promptUser() {
    int c;
    cout << "Please enter your choice: ";
    cin >> c;
    switch(c) {
      case 1: return INQUIRY;
      case 2: return SET;
      case 3: return DEPOSIT;
      case 4: return WITHDRAW;
      case 5: return QUIT;
    }
    return UNKNOWN; // Could put this in default as well, but functions the same
  }
};