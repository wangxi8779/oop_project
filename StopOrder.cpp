#include "StopOrder.h"

StopOrder::StopOrder(Stock* stock, double price, int quantity, bool isBuyOrder) {
  this->stock = stock;
  this->price = price;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool Order::match(Order* order) {
  return true;
}
