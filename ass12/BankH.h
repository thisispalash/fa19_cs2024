/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */
 
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
  
#include "BankAccountH.h"

#ifndef STRUCT_TXN
#define STRUCT_TXN

struct Txn {
  int N, Amt=0;
  AccountPtr From = nullptr;
  AccountPtr To = nullptr;
};

#endif /* STRUCT_TXN */

#ifndef BANK
#define BANK

class Bank {
  private:
    int _txn_num;
    std::map<int, AccountPtr> _acc;
    std::weak_ptr<Account> _curr;
    std::string _data_file, _txn_file;
    std::fstream _data, _txn;
  public:
    Bank();
    ~Bank() { _acc.clear(); }

    void newAcc();
    void lstAcc();
    void accDet(); // Prints the current accounts details
    void setCurrent(int);
    AccountPtr getAcc(int);
    AccountPtr getCurrent() { return _curr.lock(); }
    
    Txn transaction_do(AccountPtr,AccountPtr,int);

    AccountPtr writeAcc(AccountPtr,bool isNew = false);
    struct Txn writeTxn(struct Txn);
};

#endif /* BANK */