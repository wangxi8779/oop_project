#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>

#include "Order.h"

class Stock {
 private:
  double price;
  std::string name;
  std::vector<Order*> buyOrders;
  std::vector<Order*> sellOrders;
  std::vector<Order*> getOrders(bool);

 public:
  Stock(std::string, double);
  double getPrice();
  bool insertOrder(Order*);
  bool removeOrder(Order*);
  void matchOrder(Order*);
  void display();
};
#endif
