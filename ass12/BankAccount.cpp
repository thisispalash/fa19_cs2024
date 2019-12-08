/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include "BankAccountH.h"

Account::Account() {
  _balance = 0;
  _accnum = -1;
  _name = "default";
}
Account::Account(int b, int n, std::string na) {
  _balance = b;
  _accnum = n;
  _name = na;
}

int Account::getBalance() { return _balance; } // Can i haz cheezburgr?
int Account::setBalance(int b) {
  _balance = b;
  return getBalance();
}
int Account::getAccountNumber() { return _accnum; }
int Account::setAccountNumber(int n) {
  _accnum = n;
  return getAccountNumber();
}
std::string Account::getName() { return _name; }
std::string Account::setName(std::string na) {
  _name = na;
  return getName();
}

int Account::deposit(int x) {
  _balance += x;
  return getBalance();
}
int Account::withdraw(int x) {
  if(x>_balance || x<=0) return -1;
  _balance -= x;
  return getBalance();
}