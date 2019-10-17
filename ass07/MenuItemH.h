/*  
 *  CS 2024 ass07
 *  Author: Palash A. [pa334]
 *  Date: October 17, 2019
 *
 */

#include <iostream>
using namespace std;

class Item {
  private:
    string title;
    char x;
  public:
    Item(string,char);
    char getPrompt();
  friend ostream& operator<< (ostream& os, Item &i);
};