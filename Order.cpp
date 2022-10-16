#include "Order.h"

Order::Order(double price, int quantity, bool isBuyOrder) {
  // this->price = price;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool Order::match(Order* order) {
  return true;
}

double Order::bidPrice() {
  return 0;
}

void Order::cancel() {
  status = "cancelled";
}

bool Order::isFilled() {
  return status == "filled";
}

bool Order::getIsBuyOrder() {
  return isBuyOrder;
}

int Order::getQuantity() {
  return quantity;
}

bool Order::addTransaction(Transaction transaction) {
  transactions.push_back(transaction);
  return true;
}
