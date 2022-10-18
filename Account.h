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
 //defult constructor
  Account(std::string password, std::string name, std::string phone,
          std::string email, std::string status, std::string type);
 //constructor
  bool login(std::string email, std::string password);
 //function that lets user login
  void setStatus(std::string);
 //sets the status of the user
  void setType(std::string);
 //sets the type varible
  std::string getType();
 //returns type varible
  std::string getName();
 //returns name varible
  std::string getEmail();
 //returns email
  std::string toRow();
  virtual void displayWatchlist(){};
 //prints watchlist data members
  virtual void addStock(Stock*){};
 //adds stock to users account
  virtual void removeStock(Stock*){};
 //removes stock from users account
  virtual StockPortfolio* buy(Stock* stock, int quantity, double price,
                     std::string orderType) {return NULL;};
 //buys stock with info given 
  virtual StockPortfolio* sell(Stock* stock, int quantity, double price,
                      std::string orderType) {return NULL;};
 //sell stock from info given
  double deposit(double);
  double withdraw(double);
  double getBalance();
 //returns balance
  ~Account();
 //defult constructor
};
#endif
