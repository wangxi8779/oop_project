#include "Order.h"

Order::Order(Stock* stock, double price, int quantity, bool isBuyOrder) {
  this->stock = stock;
  this->quantity = quantity;
  this->filledQuantity = 0;
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

bool Order::isMarketOrder() {
  return false;
}

int Order::getQuantity() {
  return quantity;
}

int Order::getFilledQuantity() {
  return filledQuantity;
}

int Order::getUnfilledQuantity() {
  return quantity - filledQuantity;
}

void Order::addTransaction(Transaction transaction) {
  filledQuantity += transaction.getQuantity();
  if (filledQuantity >= quantity) {
    status = "filled";
  }
  transactions.push_back(transaction);
}

std::vector<Transaction> Order::getTransactions() {
  return transactions;
}
