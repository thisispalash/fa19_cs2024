/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 20, 2019
 *
 */

class Bank {
  private: int balance;
  public:
    Bank();
    Bank(int);

    int getBalance();
    int setBalance(int);
    int deposit(int);
    int withdraw(int);
};