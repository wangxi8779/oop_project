#ifndef TRADE_H
#define TRADE_H

#include <string>
#include <vector>

#include "Member.h"
#include "StockPortfolio.h"

class Trader : public Member {
 private:
  std::vector<StockPortfolio> stockPortfolios; 

 public:
  Trader(std::string password, std::string name, std::string phone,
          std::string email, std::string status, std::string type):Member(password, name, phone, email, status, type){};
  StockPortfolio* buy(Stock* stock, int quantity, double price,
                     std::string orderType);
  StockPortfolio* sell(Stock* stock, int quantity, double price,
                      std::string orderType);
  StockPortfolio* getStockPortfolio(Stock*);
  void addStockPortfolio(StockPortfolio);
  void displayWatchlist();
};
#endif
