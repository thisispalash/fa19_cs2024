/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include <iostream>
#include <string>

#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

class Account {
  private: 
    int _accnum, _balance;
    std::string _name;
  public:
    Account();
    Account(int,int,std::string);
    ~Account() { std::cout << "Deleting account of " << _name << "..\n"; }

    int getBalance();
    int setBalance(int);
    int getAccountNumber();
    int setAccountNumber(int);
    std::string getName();
    std::string setName(std::string);

    int deposit(int);
    int withdraw(int);
};

typedef std::shared_ptr<Account> AccountPtr;

#endif /* BANK_ACCOUNT */