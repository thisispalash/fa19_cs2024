/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 25, 2019
 *
 */

#include "BankAccountH.h"

/* Constructors */
Bank::Bank() {
  this->balance = 0;
}
Bank::Bank(int b) {
  this->balance = b;
}

/* Functions */
int Bank::getBalance() { return this->balance; } // Can i haz cheezburgr?
int Bank::setBalance(int b) {
  this->balance = b;
  return this->getBalance();
}
int Bank::deposit(int x) {
  this->balance += x;
  return this->getBalance();
}
int Bank::withdraw(int x) {
  if(x>this->balance || x<=0)
    return -1;
  this->balance -= x;
  return this->getBalance();
}