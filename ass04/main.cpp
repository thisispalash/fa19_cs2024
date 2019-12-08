/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 20, 2019
 *
 */

/* To run: 
 $ clang -lstdc++ -o ass04.out Menu.cpp BankAccount.cpp main.cpp
 $ ./ass04.out
 */


#include <iostream>
#include "MenuH.h"
#include "BankAccountH.h"

using namespace std;

// Set a balance
int setBalance(Bank* b) {
  cout << "Enter new balance: ";
  int x; cin >> x;
  return b->setBalance(x);
}

// Deposit some money in the account
int deposit(Bank* b) {
  cout << "Deposit amount: ";
  int x; cin >> x;
  return b->deposit(x);
}

// Dolla Dolla Bills YO
int withdraw(Bank* b) {
  cout << "Withdrawal amount: ";
  int x; cin >> x;
  int res = b->withdraw(x);
  if(res>=0)
    return res;
  cout << "Invalid amount. Please try again." << endl;
  return b->getBalance();
}

// Entry point of the program
int main(int argc, char* argv[]) {
  int bal; Menu m; Bank b = Bank();
  while(1) {
    m.showMenu();
    switch(m.promptUser()) {
      case INQUIRY: cout<<"Current balance: " << b.getBalance() << endl;
        continue;
      case SET: bal = setBalance(&b); 
        break;
      case DEPOSIT: bal = deposit(&b);
        break;
      case WITHDRAW: bal = withdraw(&b);
        break;
      case QUIT: cout << "bye." << endl; 
        return 0;
      case UNKNOWN: cout << "Unknown choice, please try again." << endl; 
        continue;
      default: cout << "Hmm, this line should not have been executed. Please contact the developer.";
    }
    cout << "Updated balance to " << bal << endl;
  }
}