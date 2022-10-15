#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Account.h"
//#include "Trader.h"
using namespace std;

int main() {
  vector<Account> accounts;
  ifstream accountsFile("accounts.csv");
  string name, email, password, phone, status, type;
  Account account;
  while(accountsFile.peek() != EOF) {
    getline(accountsFile, name, ',');
    getline(accountsFile, email, ',');
    getline(accountsFile, password, ',');
    getline(accountsFile, phone, ',');
    getline(accountsFile, status, ',');
    getline(accountsFile, type, ',');
    if (type == "admin") {
      account = Account(password, name, phone, email, status);
    }
    else if (type == "trader") {
      account = Account(password, name, phone, email, status);
    }
    else {
      account = Account(password, name, phone, email, status);
    }
    accounts.push_back(account);
  }
   

  // read accounts from a csv file
  

  // Login
  Account* currentUser = NULL;
  while (!currentUser) {
    string email;
    string password;
    cout << "please input email" << endl;
    cin >> email;
    cout << "please input password" << endl;
    cin >> password;
    for (int i = 0; i < 10; i++) {
      if (accounts[i].login(email, password)) {
        currentUser = &accounts[i];
        break;
      }
    }
    if (currentUser) {
      cout << "login successfully" << endl;
    } else {
      cout << "email or password is incorrect, please input again" << endl;
    }
  }
}