/*  
 *  CS 2024 ass10
 *  Author: Palash A. [pa334]
 *  Date: Nov 10, 2019
 *
 */

#include "BankAccountH.h"

Account::Account() {
  this->balance = 0;
  this->accnum = -1;
  this->name = "default";
}
Account::Account(int b, int n, std::string na) {
  this->balance = b;
  this->accnum = n;
  this->name = na;
}

int Account::getBalance() { return this->balance; } // Can i haz cheezburgr?
int Account::setBalance(int b) {
  this->balance = b;
  return this->getBalance();
}
int Account::getAccountNumber() { return this->accnum; }
int Account::setAccountNumber(int n) {
  this->accnum = n;
  return this->getAccountNumber();
}
std::string Account::getName() { return this->name; }
std::string Account::setName(std::string na) {
  this->name = na;
  return this->getName();
}

int Account::deposit(int x) {
  this->balance += x;
  return this->getBalance();
}
int Account::withdraw(int x) {
  if(x>this->balance || x<=0)
    return -1;
  this->balance -= x;
  return this->getBalance();
}