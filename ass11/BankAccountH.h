/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Nov 25, 2019
 *
 */

#include <iostream>
#include <string>
using namespace std;

class Account {
  private: 
    int accnum, balance;
    string name;
  public:
    Account();
    Account(int,int,string);

    int getBalance();
    int setBalance(int);
    int getAccountNumber();
    int setAccountNumber(int);
    string getName();
    string setName(string);

    int deposit(int);
    int withdraw(int);
};