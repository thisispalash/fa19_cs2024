/*  
 *  CS 2024 ass11
 *  Author: Palash A. [pa334]
 *  Date: Nov 28, 2019
 *
 */

#include "BankH.h"

/* 
 * Constructor and Destructor 
 */

Bank::Bank() {
  this->_data.open("_acc.dat",ios::in|ios::out|ios::app);
  // Load the map of accounts from file
  if(this->_data) { 
    this->_data.seekp(0);
    string str, delim = ",";
    while(getline(this->_data,str)) {
      if(str.find(delim) == string::npos) break;
      int pos = str.find(delim);
      int num = stoi(str.substr(0,pos));
      str.erase(0, (pos + delim.length()));
      pos = str.find(delim);
      string name = str.substr(0,pos);
      str.erase(0, (pos + delim.length()));
      pos = str.find(delim);
      int bal = stof(str.substr(0,pos)); // TODO Make float
      this->_acc[num] = new Account(bal,num,name); // add to runtime map
    }
  } _data.close();
  this->_txn.open("_txn.dat",ios::in|ios::out|ios::app);
  // Get last transaction number
  if(this->_txn) {
    this->_txn.seekp(0); // Make efficient by going to last line only
    string str; while(getline(this->_txn,str)); // Jump to last line
    int pos = str.find(":");
    string num_str = (pos!=string::npos)? str.substr(0,pos):"0";
    this->_txn_num = stoi(num_str);
    cout << "Transactions done: " << this->_txn_num << endl;
  } _txn.close();
  this->_curr = NULL;
}

Bank::~Bank() {
  delete this->_curr;
  this->_acc.clear();
  this->_data.close();
  this->_txn.close();
}


/* 
 * Account ops 
 */

void Bank::newAcc() {
  cout << "Enter Account Name: ";
  string name; cin >> name;
  int num; do {
    cout << "Enter Account Number: ";
    cin >> num;
    if(this->_acc.count(num) != 0) cout << "Account Number exists; try again\n";
    else break; // break only on unique number
  } while(1);
  cout << "Enter Opening Balance: ";
  int bal; cin >> bal;
  this->_curr = new Account(bal,num,name); // Select new account
  this->_acc[num] = this->_curr; // Add to existing map
  this->writeAcc(this->_curr); // Write to file
  cout << "Created new account for " << name << endl;
}

void Bank::lstAcc() {
  int size = this->_acc.size();
  cout << "Number of accounts: " << size << endl;
  if(size==0) { return; }
  cout << "AccNum\t:\tName\t:\tBalance" << endl;
  map<int,Account*>::iterator itr; // Iterator for map of accounts
  for(itr=this->_acc.begin(); itr!=this->_acc.end(); ++itr ) {
    cout << itr->first;
    cout << "\t:\t";
    cout << itr->second->getName();
    cout << "\t:\t";
    cout << itr->second->getBalance();
    cout << endl;
  }
}

void Bank::accDet(Account* acc) {
  if(acc == NULL) { // check for selected account
    cout << "No account selected." << endl;
    return;
  }
  cout << "Selected Account Details:" << endl;
  cout << "Account Number:\t" << acc->getAccountNumber() << endl;
  cout << "Account Name:\t" << acc->getName() << endl;
  cout << "Account Bal.:\t" << acc->getBalance() << endl;
}

Account* Bank::setCurrent(int num) {
  if(this->_acc.count(num)!=0) this->_curr = this->_acc.find(num)->second;
  else cout << "Account number not found. Please try again. Current account not changed." << endl;
  return this->_curr; // returns previous if key not found
}

struct Txn Bank::transaction_do(Account* from, Account* to, int amt) {
  if(from->getBalance() < amt) {
    cout << "Insufficient balance. Aborting transaction." << endl;
    return {};
  }
  from->withdraw(amt);
  this->writeAcc(from);
  to->deposit(amt);
  this->writeAcc(to);
  struct Txn txn;
  txn.N = ++this->_txn_num;
  txn.From = from;
  txn.To = to;
  txn.Amt = amt;
  this->writeTxn(txn);
  return txn;
}


/* 
 * File Ops : Not writing to file!!
 */

Account* Bank::getAcc(int num) {
  return this->_acc.find(num)->second; // Add check for no account
}

Account* Bank::writeAcc (Account* acc) {
  this->_data.open("_acc.dat",ios::in|ios::out);
  this->_data.seekg(0); 
  int num = acc->getAccountNumber(), pos = 0;
  string str; while(getline(this->_data,str)) {
    pos = str.find(",");
    int i = stoi(str.substr(0,pos));
    if(i == num) {
      // 1. Delete string until only balance remains
      // 2. Move put position to read minus length of balance
      // 3. Write new balance
      str.erase(0,pos+1); // remove accnum
      str.erase(0,acc->getName().length()+1); // remove name
      int offset = int(this->_data.tellg()) - str.length() - 1;
      this->_data.seekp(offset);
      this->_data << acc->getBalance() << endl;
      this->_data.close();
      return acc;
    }
  } this->_data.close();
  // Account was not found and we have reached EOF
  this->_data.open("_acc.dat",ios::app); // TODO why close and reopen
  if(this->_data) {
    this->_data << acc->getAccountNumber();
    this->_data << ",";
    this->_data << acc->getName();
    this->_data << ",";
    this->_data << acc->getBalance();
    this->_data << endl;
  } else cout << "Not write to file :(\n";
  this->_data.close();
  return acc;
}

struct Txn Bank::readTxn (int num) {
  _txn.seekg(0); int pos = 0;
  string str; while(getline(this->_txn,str)) {
    pos = str.find(":");
    if (pos == string::npos) return {}; // txn_num not found
    int i = stoi(str.substr(0,pos));
    if(i == num) {
      str.erase(0,pos+2); // +2 because ": ".length() = 2
      break;
    }
  }
  struct Txn txn; txn.N = num;
  pos = str.find(" -> ");
  txn.From = this->_acc.find(stoi(str.substr(0,pos)))->second;
  str.erase(0,pos+4); // +4 because " -> ".length() = 4
  pos = str.find("; $");
  txn.To = this->_acc.find(stoi(str.substr(0,pos)))->second;
  str.erase(0,pos+3); // +3 because "; $".length() = 3
  txn.Amt = stoi(str);
  return txn;
}

struct Txn Bank::writeTxn (struct Txn txn) {
  this->_txn.open("_txn.dat",ios::app);
  if(this->_txn) {
    this->_txn << txn.N;
    this->_txn << ": ";
    this->_txn << txn.From->getAccountNumber();
    this->_txn << " -> ";
    this->_txn << txn.To->getAccountNumber();
    this->_txn << "; $";
    this->_txn << txn.Amt;
    this->_txn << endl;
  } else cout << "Not write\n";
  this->_txn.close();
  return txn;
}