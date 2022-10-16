#include "StopOrder.h"

StopOrder::StopOrder(double price, int quantity, bool isBuyOrder) {
  this->price = price;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool Order::match(Order* order) {
  return true;
}
