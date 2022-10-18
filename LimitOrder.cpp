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
  int transactionQuantity = 0;
  double transactionPrice = 0;
  if (isBuyOrder) {
    if (bidPrice() >= order->bidPrice()) {
      if (getUnfilledQuantity() >= order->getUnfilledQuantity()) {
        transactionQuantity = order->getUnfilledQuantity();
      } else {
        transactionQuantity = getUnfilledQuantity();
      }
      if (order->isMarketOrder()) {
        transactionPrice = price;
      } else {
        transactionPrice = order->bidPrice();
      }
      addTransaction(Transaction(transactionPrice, transactionQuantity));
      order->addTransaction(
          Transaction(transactionPrice, transactionQuantity));
      stock->setPrice(transactionPrice);
      return true;
    } else {
      return false;
    }
  } else {
    if (bidPrice() <= order->bidPrice()) {
      if (getUnfilledQuantity() >= order->getUnfilledQuantity()) {
        transactionQuantity = order->getUnfilledQuantity();
      } else {
        transactionQuantity = getUnfilledQuantity();
      }
      transactionPrice = price;
      addTransaction(Transaction(transactionPrice, transactionQuantity));
      order->addTransaction(
          Transaction(transactionPrice, transactionQuantity));
      stock->setPrice(transactionPrice);
      return true;
    } else {
      return false;
    }
  }
}

double LimitOrder::bidPrice() { return price; }

LimitOrder::~LimitOrder() {}
