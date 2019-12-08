/*  
 *  CS 2024 ass12
 *  Author: Palash A. [pa334]
 *  Date: Dec 8, 2019
 *
 */

#include "BankH.h"

/* 
 * Constructor(s) 
 */

Bank::Bank() {
  _data_file = "_acc.dat"; _txn_file = "_txn.dat"; // Allow custom names?
  _curr = AccountPtr(nullptr);

    // Load the map of accounts from file
  _data.open(_data_file,std::ios::in|std::ios::out|std::ios::app);
  if(_data) { 
    _data.seekg(0); // Read from beginning of file
    std::string str, delim = ","; // csv format
    while(getline(_data,str)) {
      if(str.find(delim) == std::string::npos) break; // Empty line
      int pos = str.find(delim);
      int num = stoi(str.substr(0,pos));
      str.erase(0, (pos + delim.length())); // Delete accNum
      pos = str.find(delim);
      std::string name = str.substr(0,pos);
      str.erase(0, (pos + delim.length())); // Delete name
      _acc[num] = AccountPtr(new Account(stoi(str),num,name)); // add to runtime map
    }
  } _data.close();

    // Get last transaction number
  _txn.open("_txn.dat",std::ios::in|std::ios::out|std::ios::app);
  if(_txn) {
    _txn.seekg(int(_txn.tellg())-57);
    std::string str; getline(_txn,str);
    int pos = str.find(":");
    std::string num_str = (pos!=std::string::npos)? str.substr(0,pos):"0 ";
    _txn_num = stoi(num_str);
    std::cout << "Transactions done: " << _txn_num << std::endl;
  } _txn.close();
}

/* 
 * Account ops 
 */

void Bank::newAcc() {
  std::cout << "Enter Account Name: ";
  std::string name; std::cin >> name; // Can this be done in one statement?
  int num; do {
    std::cout << "Enter Account Number: ";
    std::cin >> num;
    if(_acc.count(num)>0) std::cout << "Account Number exists; try again\n";
    else break; // break only on unique number
  } while(1);
  std::cout << "Enter Opening Balance: "; // LOL set to default maybe?
  int bal; std::cin >> bal;
  _acc[num] = AccountPtr(new Account(bal,num,name)); // Add to existing map
  writeAcc(_acc[num],1); // Write to file
  std::cout << "Created new account for " << name << std::endl;
}

void Bank::lstAcc() {
  int size = _acc.size();
  std::cout << "Number of accounts: " << size << std::endl;
  if(size==0) { return; }
  std::cout << "AccNum\t:\tName\t:\tBalance" << std::endl;
  std::map<int,AccountPtr>::iterator itr; // Iterator for map of accounts
  int curr_acc = (_curr.lock())? _curr.lock()->getAccountNumber():-1;
  std::for_each(_acc.begin(),_acc.end(),[curr_acc](std::pair<int,AccountPtr> elem) {
    std::cout << elem.first;
    std::cout << "\t:\t";
    std::cout << elem.second->getName();
    std::cout << "\t:\t";
    if(elem.first == curr_acc) std::cout << elem.second->getBalance();
    else std::cout << "XXX"; // Privacy
    std::cout << std::endl;
  });
}

void Bank::accDet() {
  if(_curr.lock() == nullptr) { // check for selected account
    std::cout << "No account selected." << std::endl;
    return;
  } AccountPtr acc(_curr);
  std::cout << "Selected Account Details:" << std::endl;
  std::cout << "Account Number:\t" << acc->getAccountNumber() << std::endl;
  std::cout << "Account Name:\t" << acc->getName() << std::endl;
  std::cout << "Account Bal.:\t" << acc->getBalance() << std::endl;
}

void Bank::setCurrent(int num) {
  if(_acc.count(num)>0) _curr = _acc.find(num)->second;
  else std::cout << "Account number not found. Please try again. Current account not changed.\n";
}

AccountPtr Bank::getAcc(int num) {
  if (_acc.count(num)>0) return _acc.find(num)->second;
  return nullptr;
}

struct Txn Bank::transaction_do(AccountPtr from, AccountPtr to, int amt) {
  if(from->getBalance() < amt) {
    std::cout << "Insufficient balance. Aborting transaction." << std::endl;
    return {};
  }
  from->withdraw(amt); writeAcc(from);
  to->deposit(amt); writeAcc(to);
  struct Txn txn;
  txn.N = ++_txn_num;
  txn.From = from;
  txn.To = to;
  txn.Amt = amt;
  writeTxn(txn); 
  std::cout << "Txn Number: "<<txn.N << "; Sent $" << amt << std::endl;
  return txn;
}


/* 
 * File Ops
 */


std::string Bank::padAccNum(int num, int len) {
  std::string ret = "";
  for(int i=len; i>std::to_string(num).length(); i--) ret += "0";
  ret += std::to_string(num);
  return ret;
}
std::string Bank::padName(std::string name, int len) {
  std::string ret = name;
  for(int i=name.length(); i<len; i++) ret += " ";
  return ret;
}
std::string Bank::padBalance(int bal, int len) {
  std::string ret = "";
  for(int i=len; i>std::to_string(bal).length(); i--) ret += " ";
  ret += std::to_string(bal);
  return ret;
}
std::string Bank::padTxnNum(int num, int len) {
  std::string ret = "";
  for(int i=len; i>std::to_string(num).length(); i--) ret += "0";
  ret += std::to_string(num);
  return ret;
}

AccountPtr Bank::writeAcc (AccountPtr acc, bool isNew) {
  if (isNew) {
     _data.open(_data_file,std::ios::app);
    if(_data) {
      _data << padAccNum(acc->getAccountNumber());
      _data << ",";
      _data << padName(acc->getName());
      _data << ",";
      _data << padBalance(acc->getBalance());
      _data << std::endl;
    } else std::cout << "Could not add account to file. Please exit and try again.\n";
    _data.close();
  } else {
    int num = acc->getAccountNumber(), pos = 0;
    _data.open(_data_file,std::ios::in|std::ios::out);
    if(_data) {
      std::string str; while(getline(_data,str)) {
        pos = str.find(",");
        int i = stoi(str.substr(0,pos));
        if(i == num) {
          // 1. Delete string until only balance remains
          // 2. Move put position to read minus length of balance
          // 3. Write new balance
          str.erase(0,pos+1); // remove accnum
          str.erase(0,str.find(",")+1); // remove name
          int offset = int(_data.tellg()) - 8; // len(balance+"\n")
          _data.seekp(offset);
          _data << padBalance(acc->getBalance()) << std::endl;
          _data.close();
          break;
        } /* inner if */
      } /* while loop */
    } else std::cout << "Balance not updated. Please try again." << std::endl;
  }
  _data.close();
  return acc;
}

struct Txn Bank::writeTxn (struct Txn txn) {
  _txn.open(_txn_file,std::ios::app);
  if(_txn) {
    _txn << padTxnNum(txn.N);
    _txn << ": ";
    _txn << padAccNum(txn.From->getAccountNumber());
    _txn << " -> ";
    _txn << padAccNum(txn.To->getAccountNumber());
    _txn << "; ";
    _txn << padBalance(txn.Amt);
    _txn << "$" << std::endl;
  } else std::cout << "Transaction not written to file. Please try again\n";
  _txn.close();
  return txn;
}