#ifndef STOCK_H;
#define STOCK_H ;
#include <string>
#include <vector>

#include "Order.h"

class Stock {
 private:
  double price;
  std::string name;
  std::vector<Orders*> orders;

 public:
  double get_price();
  bool addOrder(Order*);
  bool removeOrder(Order*);
  void matchOrder();
};
#endif
