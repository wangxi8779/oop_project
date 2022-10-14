#include "StockPortfolio.h"

StockPortfolio::StockPortfolio() {}

StockPortfolio::StockPortfolio(Stock* stock) {
  this->stock = stock;
  this->average_price = 0;
  this->gain = 0;
  this->quantity = 0;
}

bool StockPortfolio::place_order(Order* order) {
  orders.push_back(order);
  return true;
}
bool StockPortfolio::cancel_order(Order* order) {
  for(int i = 0; i < orders.size(); i++) {
    if (orders.at(i) == order) {
      orders.deleteAt(i);
      return true;
    }
  }
  return false;
}
