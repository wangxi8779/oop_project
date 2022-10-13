#ifndef TRADE_H;
#define TRADE_H;
#include <string>
#include <vector>
#include "StockPortfolio.h"

class Trade {
    private:
    double balance;
    std::vector<StockPortfolio> portfolio;

    public:
    double deposit(double)
    double withdraw(double);
    stockPortfolio buy(Stock *stock,int quantity,double price, std::string orderType)
    stockPortfolio sell(Stock *stock,int quantity,double price, std::string orderType)

};


#endif 