#ifndef STOP_ORDER_H
#define STOP_ORDER_H

#include <string>
#include <vector>

#include "MarketOrder.h"

class StopOrder : public MarketOrder {
 private:
  double price;

 public:
  StopOrder(Stock*, double, int, bool);
  bool match(Order*);
};
#endif
