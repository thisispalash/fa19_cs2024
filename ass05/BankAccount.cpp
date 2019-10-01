/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */

#include "BankAccountH.h"

/* Constructors */
BankAccount::BankAccount() {
  this->balance = 0;
  this->accnum = -1;
  this->name = "default";
}
BankAccount::BankAccount(int b, int n, string na) {
  this->balance = b;
  this->accnum = n;
  this->name = na;
}

/* Functions */
int BankAccount::getBalance() { return this->balance; } // Can i haz cheezburgr?
int BankAccount::setBalance(int b) {
  this->balance = b;
  return this->getBalance();
}
int BankAccount::getAccountNumber() { return this->accnum; }
int BankAccount::setAccountNumber(int n) {
  this->accnum = n;
  return this->getAccountNumber();
}
string BankAccount::getName() { return this->name; }
string BankAccount::setName(string na) {
  this->name = na;
  return this->getName();
}

/* Unused in current assignment
int BankAccount::deposit(int x) {
  this->balance += x;
  return this->getBalance();
}
int BankAccount::withdraw(int x) {
  if(x>this->balance || x<=0)
    return -1;
  this->balance -= x;
  return this->getBalance();
}
*/