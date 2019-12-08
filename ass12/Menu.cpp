/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include "MenuH.h"

Menu::Menu(Item* items[], int len, std::string title, char x) : Item(title, x) {
  for(int i=0; i<len; i++)
    _items.push_back(items[i]);
}

bool Menu::select() {
  std::cout << "\n===== " << _title << " =====\n";
  for(int i=0; i<_items.size(); i++)
    _items[i]->display();
  std::cout << "===============\n";
  std::cout << "Enter your choice: ";
  char c; std::cin >> c; 
  bool correct = false; // To check for an invalid selection
  for(int i=0; i<_items.size(); i++) {
    if(c == _items[i]->getPrompt()) {
      if(_items[i]->select()) select(); // Continue same menu
      correct = true;
    }
  }
  if(!correct) {
    std::cout << "INVALID CHOICE\n";
    std::cout << "--------------------\n";
    select();
  }
  return 1; // go back to previous menu and display that
}

void Menu::display() {
  std::cout << _x << ". " << _title << ">\n";
}