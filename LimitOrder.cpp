#include "LimitOrder.h"

LimitOrder::LimitOrder(double price, int quantity, bool isBuyOrder) {
  this->price = price;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool LimitOrder::match(Order* order) {
  return true;
}
