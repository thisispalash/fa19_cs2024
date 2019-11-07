/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 2, 2019
 *
 */

#ifndef BASE_H
#define BASE_H
  #include <iostream>
  #include <vector>
#endif

class Item {
public:
  Item(std::string, char);
  virtual bool select() = 0;
  virtual void display() = 0;
  char getPrompt() { return x; }
protected:
  char x;
  std::string title;
};