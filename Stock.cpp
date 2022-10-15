#include "Stock.h"

double Stock::getPrice() { return price; }
bool Stock::insertOrder(Order* order) {
  std::vector<Order*> orders = getOrders(order->getIsBuyOrder());
  orders.push_back(order);
  return true;
}
bool Stock::removeOrder(Order* order) {
  std::vector<Order*> orders = getOrders(order->getIsBuyOrder());
  for (int i = 0; i < orders.size(); i++) {
    if (orders.at(i) == order) {
      orders.erase(orders.begin() + i);
      return true;
    }
  }
  return false;
}
void Stock::matchOrder(Order* order) {
  std::vector<Order*> pendingOrders = getOrders(!(order->getIsBuyOrder()));
  for(Order* pendingOrder : pendingOrders) {
    if (pendingOrder->match(order)) {
      if(pendingOrder->isFilled()) {
        pendingOrders.erase(pendingOrders.begin());
      }
      if(order->isFilled()) {
        return;
      }
    }
    else {
      insertOrder(order);
    }
  }
}

std::vector<Order*> Stock::getOrders(bool isBuyOrder) {
  if (isBuyOrder) {
    return buyOrders;
  } else {
    return sellOrders;
  }
}
