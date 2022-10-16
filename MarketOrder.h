#ifndef MARKET_ORDER_H
#define MARKET_ORDER_H

#include <string>
#include <vector>

#include "Order.h"

class MarketOrder : public Order {
 public:
  MarketOrder(int, bool);
  bool match(Order*);
  double bidPrice();
};
#endif
