#include "Order.h"

Order::Order(double price, int quantity, bool isBuyOrder) {
  // this->price = price;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool Order::match(Order* order) {

}

void Order::cancel() {
  status = "cancelled";
}

bool Order::isFilled() {
  status == "filled";
}

bool Order::getIsBuyOrder() {
  return isBuyOrder;
}

bool Order::addTransaction(Transaction transaction) {
  transactions.push_back(transaction);
  return true;
}
