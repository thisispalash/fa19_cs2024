/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 30, 2019
 *
 */

#include "MenuH.h"

Menu::Menu(Item* items[], int len, std::string title, char x) : Item(title, x) {
  for(int i=0; i<len; i++)
    this->items.push_back(items[i]);
}

bool Menu::select() {
  std::cout << "\n===== " << this->title << " =====\n";
  for(int i=0; i<this->items.size(); i++)
    this->items[i]->display();
  std::cout << "===============\n";
  std::cout << "Enter your choice: ";
  char c; std::cin >> c; 
  bool correct = false; // To check for an invalid selection
  for(int i=0; i<this->items.size(); i++) {
    if(c == this->items[i]->getPrompt()) {
      if(this->items[i]->select()) // Continue displaying same menu
        this->select();
      correct = true;
    }
  }
  if(!correct) {
    std::cout << "INVALID CHOICE\n";
    std::cout << "--------------------\n";
    this->select();
  }
  return 1; // go back to previous menu and display that
}

void Menu::display() {
  std::cout << this->x << ". " << this->title << ">\n";
}