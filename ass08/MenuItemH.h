/*  
 *  CS 2024 ass08
 *  Author: Palash A. [pa334]
 *  Date: October 29, 2019
 *
 */


class Item {
public:
  Item(char, std::string);
  virtual bool select() = 0;
  virtual void display() = 0;
  char getPrompt() { return x; }
protected:
  char x;
  std::string title;
};