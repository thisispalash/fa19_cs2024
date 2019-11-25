/*  
 *  CS 2024 ass11
 *  Author: Palash A. [pa334]
 *  Date: Nov 25, 2019
 *
 */

#include "BankH.h"

Bank::Bank() {
  if(this->acc.empty()) this->curr = NULL;
  else this->curr = this->acc.begin()->second; // Select the first account
}

Bank::~Bank() {
  this->acc.clear();
  delete this->curr;
} // free up memory

void Bank::newAcc() {
  cout << "Enter Account Name: ";
  string name; cin >> name;
  int num;
  do {
    cout << "Enter Account Number: ";
    cin >> num;
    if(this->acc.count(num) != 0) cout << "Account Number exists; try again\n";
    else break; // break only on unique number
  } while(1);
  cout << "Enter Opening Balance: ";
  int bal; cin >> bal;
  this->acc.insert({num, new Account(bal,num,name)});
  cout << "Created new account for " << name << endl;
}

void Bank::lstAcc() {
  int size = this->acc.size();
  cout << "Number of accounts: " << size << endl;
  if(size==0) { return; }
  cout << "AccNum\t:\tName\t:\tBalance" << endl;
  map<int,Account*>::iterator itr; // Iterator for map of accounts
  for(itr=this->acc.begin(); itr!=this->acc.end(); ++itr ) {
    cout << itr->first;
    cout << "\t:\t";
    cout << itr->second->getName();
    cout << "\t:\t";
    cout << itr->second->getBalance();
    cout << endl;
  }
}

void Bank::accDet(Account* acc) {
  if(acc == NULL) { // check for selected account
    cout << "No account selected." << endl;
    return;
  }
  cout << "Selected Account Details:" << endl;
  cout << "Account Number:\t" << acc->getAccountNumber() << endl;
  cout << "Account Name:\t" << acc->getName() << endl;
  cout << "Account Bal.:\t" << acc->getBalance() << endl;
}

Account* Bank::setCurrent(int num) {
  if(this->acc.count(num)!=0) this->curr = this->acc.find(num)->second;
  else cout << "Account number not found. Please try again. Current account not changed." << endl;
  return this->curr; // returns previous if key not found
}