/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 25, 2019
 *
 */

#include "MenuH.h"

// Pretty print
void Menu::showMenu() {
  cout << endl;
  cout << "--- Menu ---" << endl;
  cout << "1. Balance Inquiry" << endl;
  cout << "2. Set Balance" << endl;
  cout << "3. Deposit" << endl;
  cout << "4. Withdraw" << endl;
  cout << "5. Quit" << endl;
  cout << "------------" << endl;
}

// Convert the choice to `ItemCode`
ItemCode Menu::promptUser() {
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
} // Possible addition of error catching