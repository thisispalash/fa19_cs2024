/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */
#include <iostream> 
using namespace std; 

class BankAccount {
  private: 
    int accnum, balance;
    string name;
  public:
    BankAccount();
    BankAccount(int,int,string);

    int getBalance();
    int setBalance(int);
    int getAccountNumber();
    int setAccountNumber(int);
    string getName();
    string setName(string);

    // Unused in current assignment
    /* int deposit(int);
     * int withdraw(int); */
};