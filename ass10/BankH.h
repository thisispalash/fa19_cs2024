/*  
 *  CS 2024 ass10
 *  Author: Palash A. [pa334]
 *  Date: Nov 11, 2019
 *
 */
 
#include "BankAccountH.h"
#include <iterator>
#include <map>

class Bank {
  private: std::map<int, Account*> acc; Account *curr;
  public:
    Bank();
    ~Bank();
    void newAcc();
    void lstAcc();
    void accDet(Account*);
    Account *getCurrent() { return curr; }
    Account *setCurrent(int);
};