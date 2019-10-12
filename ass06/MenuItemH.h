/*  
 *  CS 2024 ass06
 *  Author: Palash A. [pa334]
 *  Date: October 12, 2019
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
    void display();
    char getPrompt();
};