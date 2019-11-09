/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */
#include "BankH.h"

void Bank::newAcc() {
  cout << "Enter Account Name: ";
  string name; cin >> name;
  cout << "Enter Account Number: ";
  int num; cin >> num;
  cout << "Enter Opening Balance: ";
  int bal; cin >> bal;
  this->acc.push_back(new BankAccount(bal, num, name));
  cout << "Created new account for " << name << endl;
}

void Bank::lstAcc() {
  int size = this->acc.size();
  cout << "Number of accounts: " << size << endl;
  if(size==0) { return; }
  cout << "AccNum\t:\tName\t:\tBalance" << endl;
  for(int i=0; i<this->acc.size(); ++i) {
    BankAccount *b = this->acc[i];
    cout << b->getAccountNumber();
    cout << "\t:\t";
    cout << b->getName();
    cout << "\t:\t";
    cout << b->getBalance();
    cout << endl;
  }
}

void Bank::clear() {
  cout << "..freeing up memory" << endl;
  this->acc.clear();
}