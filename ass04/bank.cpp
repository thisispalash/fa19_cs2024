/*  
 *  CS 2024 ass04
 *  Author: Palash A. [pa334]
 *  Date: September 20, 2019
 *
 */

class Bank {
  private: int balance;
  public:
    Bank() {
      this->balance = 0;
    }
    Bank(int b) {
      this->balance = b;
    }

    int getBalance() { return this->balance; }
    int setBalance(int b) {
      this->balance = b;
      return this->getBalance();
    }
    int deposit(int x) {
      this->balance += x;
      return this->getBalance();
    }
    int withdraw(int x) {
      if(x>this->balance || x<=0)
        return -1;
      this->balance -= x;
      return this->getBalance();
    }
};