#include "LimitOrder.h"

LimitOrder::LimitOrder(Stock *stock, double price, int quantity,
                       bool isBuyOrder) {
  this->stock = stock;
  this->price = price;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool LimitOrder::match(Order *order) {
  int transaction_quantity = 0;
  double transaction_price = 0;
  if (isBuyOrder) {
    if (bidPrice() >= order->bidPrice()) {
      if (getUnfilledQuantity() >= order->getUnfilledQuantity()) {
        transaction_quantity = order->getUnfilledQuantity();
      } else {
        transaction_quantity = getUnfilledQuantity();
      }
      if (order->isMarketOrder()) {
        transaction_price = price;
      } else {
        transaction_price = order->bidPrice();
      }
      addTransaction(Transaction(transaction_price, transaction_quantity));
      order->addTransaction(
          Transaction(transaction_price, transaction_quantity));
      stock->setPrice(transaction_price);
      return true;
    } else {
      return false;
    }
  } else {
    if (bidPrice() <= order->bidPrice()) {
      if (getUnfilledQuantity() >= order->getUnfilledQuantity()) {
        transaction_quantity = order->getUnfilledQuantity();
      } else {
        transaction_quantity = getUnfilledQuantity();
      }
      transaction_price = price;
      addTransaction(Transaction(transaction_price, transaction_quantity));
      order->addTransaction(
          Transaction(transaction_price, transaction_quantity));
      stock->setPrice(transaction_price);
      return true;
    } else {
      return false;
    }
  }
}

double LimitOrder::bidPrice() { return price; }

LimitOrder::~LimitOrder() {}
