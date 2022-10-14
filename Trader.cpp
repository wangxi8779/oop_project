#include "Trader.h"

double Trader::deposit(double amount) {
  balance += amount;
  return balance;
}

double Trader::withdraw(double amount) {
  balance -= amount;
  return balance;
}

stockPortfolio Trader::buy(Stock* stock, int quantity, double price,
                           std::string orderType) {
  stockPortfolio stock_porfolio = stockPortfolio(stock);
  case orderType
  when 'market_order' {
    Order order = Order(price, quantity, true, stock); 
  }
  stock_porfolio.placeOrder(&order);
  return stock_porfolio;
}

stockPortfolio Trader::sell(Stock *stock,int quantity,double price, std::string orderType) {
  stockPortfolio stock_porfolio = stockPortfolio(stock);
  case orderType
  when 'market_order' {
    Order order = Order(price, quantity, true, stock); 
  }
  stock_porfolio.placeOrder(&order);
  return stock_porfolio;
}
