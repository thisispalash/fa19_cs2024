/*  
 *  CS 2024 ass10
 *  Author: Palash A. [pa334]
 *  Date: Nov 24, 2019
 *
 */
 
#include "BankAccountH.h"
#include <iterator>
#include <fstream>
#include <map>
using namespace std;

class Bank {
  private:
    Account *curr;
    map<int, Account*> acc;
    fstream data('data.dat', ios::in | ios::out);
    fstream txn('transactions.dat', ios::in | ios::out);
  public:
    Bank();
    ~Bank();
    
    void newAcc();
    void lstAcc();
    void accDet(Account*);
    Account* getCurrent() { return curr; }
    Account* setCurrent(int);
    
    void transaction();
};