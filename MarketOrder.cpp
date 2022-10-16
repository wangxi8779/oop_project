#include "MarketOrder.h"

MarketOrder::MarketOrder(int quantity, bool isBuyOrder) {
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool MarketOrder::match(Order* order) {
  // Work in progress
  if(isBuyOrder) {
    if (bidPrice() >= order->bidPrice()) {
      int transaction_quantity = 0;
      // addTransaction(Transaction())
    }
    return true;
  } else {
    return true;
  }
}

double MarketOrder::bidPrice() {
  if(isBuyOrder) {
    return 100000000;
  } else {
    return -1;
  }
}
