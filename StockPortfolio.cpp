#include <iostream>
#include "StockPortfolio.h"

StockPortfolio::StockPortfolio() {}

StockPortfolio::StockPortfolio(Stock* stock) {
  this->stock = stock;
  this->average_price = 0;
  this->gain = 0;
  this->quantity = 0;
}

bool StockPortfolio::placeOrder(Order* order) {
  orders.push_back(order);
  stock->matchOrder(order);
  return true;
}
bool StockPortfolio::cancelOrder(Order* order) {
  for(int i = 0; i < orders.size(); i++) {
    if (orders.at(i) == order) {
      if (order->isFilled()) {
        std::cout << "This order is filled, cannot cancel." << std::endl;
        return false;
      } else {
        order->cancel();
        return true;
      }
    }
  }
  std::cout << "This order is not found, cannot cancel." << std::endl;
  return false;
}

Stock* StockPortfolio::getStock() {
  return stock;
}
