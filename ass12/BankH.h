/*  
 *  CS 2024 ass11
 *  Author: Palash A. [pa334]
 *  Date: Nov 26, 2019
 *
 */
 

// Add header guards

#include "BankAccountH.h"
#include <map>
#include <iterator>
#include <fstream>
  
struct Txn {
  int N, Amt=0;
  Account* From = NULL;
  Account* To = NULL;
};

class Bank {
  private:
    int _txn_num;
    Account *_curr;
    map<int, Account*> _acc;
    fstream _data, _txn;
  public:
    Bank();
    ~Bank();

    void newAcc();
    void lstAcc();
    void accDet(Account*);
    Account* getCurrent() { return _curr; }
    Account* setCurrent(int);
    Txn transaction_do(Account*,Account*,int);
    
    Account* getAcc(int);
    Account* writeAcc(Account*);
    struct Txn readTxn(int);
    struct Txn writeTxn(struct Txn);
};