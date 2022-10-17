#include "Trader.h"

#include <iostream>

#include "LimitOrder.h"
#include "MarketOrder.h"

StockPortfolio* Trader::buy(Stock* stock, int quantity, double price,
                            std::string orderType) {
  StockPortfolio* portfolio = getStockPortfolio(stock);
  Order* order;
  if (orderType == "limit") {
    if (price * quantity > balance) {
      std::cout << "Not enough balance" << std::endl;
    } else {
      order = new LimitOrder(stock, price, quantity, true);
      portfolio->placeOrder(order);
    }
  } else {
    if (stock->getPrice() * quantity > balance) {
      std::cout << "Not enough balance" << std::endl;
    } else {
      order = new MarketOrder(stock, quantity, true);
      portfolio->placeOrder(order);
    }
  }
  return portfolio;
}

StockPortfolio* Trader::sell(Stock* stock, int quantity, double price,
                             std::string orderType) {
  StockPortfolio* portfolio = getStockPortfolio(stock);
  if (portfolio->getQuantity() >= quantity) {
    Order* order;
    if (orderType == "limit") {
      order = new LimitOrder(stock, price, quantity, false);
    } else {
      order = new MarketOrder(stock, quantity, false);
    }
    portfolio->placeOrder(order);
  } else {
    std::cout << "Not enough stocks" << std::endl;
  }
  return portfolio;
}

StockPortfolio* Trader::getStockPortfolio(Stock* stock) {
  // find portfolio by given stock
  for (int i = 0; i < stockPortfolios.size(); i++) {
    if (stockPortfolios.at(i).getStock() == stock) {
      stockPortfolios.at(i).refresh();
      return &stockPortfolios.at(i);
    }
  }

  // if not exists, create a new one
  StockPortfolio* stockPortfolio = new StockPortfolio(stock);
  stockPortfolios.push_back(*stockPortfolio);
  return stockPortfolio;
}

void Trader::displayWatchlist() {
  std::cout << name << "'s watchlist" << std::endl;
  for (Stock* stock : watchlist.getStocks()) {
    stock->display();
    // display stock protfolio only for trader
    StockPortfolio* stockPortfolio = getStockPortfolio(stock);
    stockPortfolio->display();
  }
}

Trader::~Trader() { stockPortfolios.clear(); }
