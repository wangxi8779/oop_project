#ifndef MARKET_ORDER_H
#define MARKET_ORDER_H

#include <string>
#include <vector>

#include "Order.h"

class MarketOrder : public Order {
 public:
  MarketOrder(Stock*, int, bool);
  MarketOrder();
  bool match(Order*);
  double bidPrice();
  bool isMarketOrder();
  ~MarketOrder();
};
#endif
