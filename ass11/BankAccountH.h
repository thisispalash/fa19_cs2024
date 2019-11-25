/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Nov 10, 2019
 *
 */

#include <iostream>

class Account {
  private: 
    int accnum, balance;
    std::string name;
  public:
    Account();
    Account(int,int,std::string);

    int getBalance();
    int setBalance(int);
    int getAccountNumber();
    int setAccountNumber(int);
    std::string getName();
    std::string setName(std::string);

    int deposit(int);
    int withdraw(int);
};