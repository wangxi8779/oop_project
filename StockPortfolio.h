#ifndef STOCKPORTFOLIO_H
#define STOCKPORTFOLIO_H

#include <string>
#include <vector>

#include "Order.h"
#include "Stock.h"

class StockPortfolio {
 private:
  Stock* stock;
  double averagePrice;
  double gain;
  int quantity;
  std::vector<Order*> orders;

 public:
  StockPortfolio();
  StockPortfolio(Stock*);
  StockPortfolio(Stock*, int);
  bool placeOrder(Order*);
  bool cancelOrder(Order*);
  double withdraw(double);
  Stock* getStock();
  int getQuantity();
  void display();
  void refresh();
  ~StockPortfolio();
};
#endif
