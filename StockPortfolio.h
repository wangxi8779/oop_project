#ifndef STOCKPORTFOLIO_H;
#define STOCKPORTFOLIO_H ;
#include <string>
#include <vector>

#include "Order.h"
#include "Stock.h"

class StockPortfolio {
 private:
  Stock* stock;
  double average_price;
  double gain;
  int quantity;
  std::vector<Order*> orders;

 public:
  StockPortfolio();
  StockPortfolio(Stock*);
  bool place_order(Order*);
  bool cancel_order(Order*);
  double withdraw(double);
  void display();
};
#endif
