#include <iostream>
#include <fstream>
#include "StockMarket.h"
#include "Admin.h"
#include "Trader.h"

StockMarket::StockMarket(std::vector<Stock*> stocks) {
  this->stocks = stocks;
  loadAccounts();
}

void StockMarket::loadAccounts() {
  std::ifstream accountsFile("accounts.csv");
  std::string name, email, password, phone, status, type;
  Account account;
  while(accountsFile.peek() != EOF) {
    getline(accountsFile, name, ',');
    getline(accountsFile, email, ',');
    getline(accountsFile, password, ',');
    getline(accountsFile, phone, ',');
    getline(accountsFile, status, ',');
    getline(accountsFile, type, '\n');
    if (type == "admin") {
      accounts.push_back(new Admin(password, name, phone, email, status, "admin", this));
    }
    else if (type == "trader") {
      accounts.push_back(new Trader(password, name, phone, email, status, "trader"));
    }
    else {
      accounts.push_back(new Member(password, name, phone, email, status, "member"));
    }
  }
}

void StockMarket::updateAccounts(){
  std::ofstream accountsFile;
  accountsFile.open("accounts.csv");
  for(Account* account : accounts) {
    accountsFile << account->toRow();
  }
  accountsFile.close();
}

Account* StockMarket::login(std::string email, std::string password) {
  for (int i = 0; i < accounts.size(); i++) {
    Account* account = accounts.at(i);
    if (account->getEmail() == email) {
      if (account->login(email, password)) {
        return accounts.at(i);
      }
    }
  }
  return NULL;
}

Account* StockMarket::findAccount(std::string name) {
  for (int i = 0; i < accounts.size(); i++) {
    if (accounts.at(i)->getName() == name) {
      return accounts.at(i);
    }
  }
  return NULL;
}
