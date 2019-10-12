/*  
 *  CS 2024 ass06
 *  Author: Palash A. [pa334]
 *  Date: October 12, 2019
 *
 */

#include "MenuH.h"

Menu::Menu(Item items[], int len) {
  for(int i=0; i<len; i++)
    this->items.push_back(items[i]); // one statement bodies do not need braces
}

void Menu::showMenu() {
  cout << "----- Menu -----" << endl;
  for(int i=0; i<this->items.size(); i++)
    this->items[i].display(); // one statement bodies do not need braces
  cout << "----- ---- -----" << endl;
}
char Menu::promptUser() {
  char x;
  cout << "Please enter your choice: ";
  cin >> x;
  for(int i=0; i<this->items.size(); i++) {
    if(x == this->items[i].getPrompt())
      return x; // one statement bodies do not need braces
  }
  return '\0';
}
