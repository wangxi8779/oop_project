#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Stock.h"
#include "StockPortfolio.h"

class Account {
 protected:
  std::string password;
  std::string name;
  std::string status;
  std::string type;
  std::string phone;
  std::string email;
  double balance;

 public:
  Account();
  Account(std::string password, std::string name, std::string phone,
          std::string email, std::string status, std::string type);
  bool login(std::string email, std::string password);
  void setStatus(std::string);
  void setType(std::string);
  std::string getType();
  std::string getName();
  std::string getEmail();
  std::string toRow();
  virtual void displayWatchlist(){};
  virtual void addStock(Stock*){};
  virtual void removeStock(Stock*){};
  virtual StockPortfolio* buy(Stock* stock, int quantity, double price,
                     std::string orderType) {return NULL;};
  virtual StockPortfolio* sell(Stock* stock, int quantity, double price,
                      std::string orderType) {return NULL;};
  double deposit(double);
  double withdraw(double);
};
#endif