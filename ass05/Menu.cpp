/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */

#include "MenuH.h"

// Pretty print
void Menu::showMenu() {
  cout << endl;
  cout << "--- Menu ---" << endl;
  cout << "1. New Account" << endl;
  cout << "2. List Account" << endl;
  cout << "3. Quit" << endl;
  cout << "------------" << endl;
}

// Convert the choice to `ItemCode`
ItemCode Menu::promptUser() {
  int c;
  cout << "Please enter your choice: ";
  cin >> c;
  switch(c) {
    case 1: return NEW;
    case 2: return LIST;
    case 3: return QUIT;
  }
  return UNKNOWN; // Could put this in default as well, but functions the same
} // Possible addition of error catching