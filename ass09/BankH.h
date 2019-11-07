/*  
 *  CS 2024 ass09
 *  Author: Palash A. [pa334]
 *  Date: Nov 2, 2019
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