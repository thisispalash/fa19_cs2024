/*  
 *  CS 2024 ass10
 *  Author: Palash A. [pa334]
 *  Date: Nov 11, 2019
 *
 */

#include "BankH.h"

Bank::Bank() {
  if(this->acc.empty()) this->curr = NULL;
  else this->curr = this->acc.begin()->second;
}

Bank::~Bank() {
  this->acc.clear();
  delete this->curr;
}

void Bank::newAcc() {
  std::cout << "Enter Account Name: ";
  std::string name; std::cin >> name;
  int num;
  do {
    std::cout << "Enter Account Number: ";
    std::cin >> num;
    if(this->acc.count(num) != 0) std::cout << "Account Number exists; try again\n";
    else break;
  } while(1);
  std::cout << "Enter Opening Balance: ";
  int bal; std::cin >> bal;
  this->acc.insert({num, new Account(bal,num,name)});
  std::cout << "Created new account for " << name << std::endl;
}

void Bank::lstAcc() {
  int size = this->acc.size();
  std::cout << "Number of accounts: " << size << std::endl;
  if(size==0) { return; }
  std::cout << "AccNum\t:\tName\t:\tBalance" << std::endl;
  std::map<int,Account*>::iterator itr;
  for(itr=this->acc.begin(); itr!=this->acc.end(); ++itr ) {
    std::cout << itr->first;
    std::cout << "\t:\t";
    std::cout << itr->second->getName();
    std::cout << "\t:\t";
    std::cout << itr->second->getBalance();
    std::cout << std::endl;
  }
}

void Bank::accDet(Account* acc) {
  if(acc == NULL) {
    std::cout << "No account selected" << std::endl;
    return;
  }
  std::cout << "Selected Account Details:" << std::endl;
  std::cout << "Account Number:\t" << acc->getAccountNumber() << std::endl;
  std::cout << "Account Name:\t" << acc->getName() << std::endl;
  std::cout << "Account Bal.:\t" << acc->getBalance() << std::endl;
}

Account* Bank::setCurrent(int num) {
  if(this->acc.count(num)!=0) this->curr = this->acc.find(num)->second;
  else std::cout << "Account number not found. Please try again." << std::endl;
  return this->curr; 
}