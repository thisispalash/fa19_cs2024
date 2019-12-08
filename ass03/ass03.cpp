/*  
 *  CS 2024 ass03
 *  Author: Palash A. [pa334]
 *  Date: September 18, 2019
 *
 */

/*
 $ To run: $ clang -lstdc++ -o ass03.out ass03.cpp menu.cpp
 $ ./ass03.out
 */


#include <iostream>
#include "menu.cpp"

using namespace std;

void printName() {
  for(int i=0; i<3; i++)
    cout << "Enoch" << endl;
}

void square() {
  int n;
  cout << "Enter number to be squared: ";
  cin >> n;
  cout << "Square of " << n << " = " << n*n << endl;
}

int main(int argc, char* argv[]) {
  Menu m;
  while(1) {
    m.showMenu();
    ItemCode c = m.promptUser();
    switch(c) {
      case PRINT: printName(); 
        break;
      case SQUARE: square(); 
        break;
      case QUIT: cout << "bye" << endl; 
        return 0;
      case UNKNOWN: cout << "Unknown choice, please try again." << endl; 
        break;
      default: cout << "Hmm, this line should not have been executed. Please contact the developer.";
    }
  }
}