#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H

#include <string>
#include <vector>
#include "Account.h"
#include "Stock.h"

class StockMarket {
 private:
  std::vector<Account*> accounts;
  std::vector<Stock> stocks;
  void loadAccounts();

 public:
  StockMarket(std::vector<Stock>);
  void updateAccounts();
  Account* login(std::string, std::string);
  Account* findAccount(std::string);
};
#endif