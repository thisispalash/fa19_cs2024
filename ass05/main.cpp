/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */

 /* To run: 
  $ clang -lstdc++ -o ass05 Menu.cpp BankAccount.cpp Bank.cpp main.cpp
  $ ./ass05
  */

#include "MenuH.h"
#include "BankH.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  Menu m; ItemCode c;
  Bank b = Bank();
  do { m.showMenu(); // Show the menu
    c = m.promptUser(); // Get the choice
    switch(c) {
      case NEW: b.newAcc();
        break;
      case LIST: b.lstAcc(); 
        break;
      case QUIT: cout << "bye." << endl;
        break;
      case UNKNOWN: cout << "Unknown choice, please try again." << endl; 
        break;
      default: cout << "Hmm, this line should not have been executed. Please contact the developer.";
    }
  } while(c != QUIT); // While user wants to continue
  b.clear(); // free memory
  return 0; // exit
}