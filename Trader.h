#ifndef TRADE_H;
#define TRADE_H ;
#include <string>
#include <vector>

#include "Member.h"
#include "StockPortfolio.h"

class Trader : public Member {
 private:
  double balance;
  std::vector<StockPortfolio> stockPortfolios; 
  StockPortfolio* getStockPortfolio(Stock*);

 public:
  Trader(std::string password, std::string name, std::string phone,
          std::string email, std::string status):Member(password, name, phone, email, status){};
  double deposit(double);
  double withdraw(double);
  StockPortfolio* buy(Stock* stock, int quantity, double price,
                     std::string orderType);
  StockPortfolio* sell(Stock* stock, int quantity, double price,
                      std::string orderType);
};
#endif
