#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H

#include <string>
#include <vector>

#include "Order.h"

class LimitOrder : public Order{
 private:
  double price;

 public:
  LimitOrder(Stock*, double, int, bool);
  bool match(Order*);
  double bidPrice();
  ~LimitOrder();
};
#endif
