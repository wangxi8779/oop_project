#ifndef ADMIN_H
#define ADMIN_H

#include <string>

#include "Account.h"
#include "StockMarket.h"

class Admin : public Account {
 private:
  StockMarket* stockMarket;
 public:
  Admin(std::string password, std::string name, std::string phone,
          std::string email, std::string status, std::string type, StockMarket* stockMarket);
  void block(Account*);
  void unblock(Account*);
  void upgrade(Account*);
  void downgrade(Account*);
  void displayWatchlist();
  void addStock(Stock*);
  void removeStock(Stock*);
};

#endif
