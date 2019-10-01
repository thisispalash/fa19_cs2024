/*  
 *  CS 2024 ass05
 *  Author: Palash A. [pa334]
 *  Date: Oct 1, 2019
 *
 */
#include "BankAccountH.h"
#include <iostream>
#include <vector> // "error: implicit instantiation of undefined template" without this ?!
using namespace std;

class Bank {
  private: vector<BankAccount*> acc;
  public:
    void newAcc();
    void lstAcc();
    void clear();
};