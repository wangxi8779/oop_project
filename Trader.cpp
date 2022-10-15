#include "Trader.h"

double Trader::deposit(double amount)
{
  balance += amount;
  return balance;
}

double Trader::withdraw(double amount)
{
  balance -= amount;
  return balance;
}

StockPortfolio* Trader::buy(Stock* stock, int quantity, double price, std::string orderType)
{
  StockPortfolio* portfolio = getStockPortfolio(stock);
  Order order = Order(price, quantity, true);
  portfolio->placeOrder(&order);
  return portfolio;
}

StockPortfolio* Trader::sell(Stock* stock, int quantity, double price, std::string orderType)
{
  StockPortfolio* portfolio = getStockPortfolio(stock);
  Order order = Order(price, quantity, false);
  portfolio->placeOrder(&order);
  return portfolio;
}

StockPortfolio* Trader::getStockPortfolio(Stock* stock) {
  for(StockPortfolio sp : stockPortfolios) {
    if (sp.getStock() == stock) {
      return &sp;
    }
  }
  
  StockPortfolio* stockPortfolio = new StockPortfolio(stock);
  stockPortfolios.push_back(*stockPortfolio);
  return stockPortfolio;
}

void Trader::displayWatchlist() {
  std::cout << name << "'s watchlist" << std::endl;
  for(Stock* stock : watchlist.getStocks()) {
    stock->display();
    StockPortfolio* stockPortfolio = getStockPortfolio(stock);
    stockPortfolio->display();
  }

}
