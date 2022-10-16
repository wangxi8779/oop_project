#include "Stock.h"

Stock::Stock(std::string name, double price) {
  this->name = name;
  this->price = price;
}

double Stock::getPrice() { return price; }

bool Stock::insertOrder(Order* order) {
  std::vector<Order*> orders = getOrders(order->getIsBuyOrder());
  for(int i = 0; i < orders.size(); i++) {
    // working in progress
  }
  orders.push_back(order);
  return true;
}

bool Stock::removeOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for (int i = 0; i < buyOrders.size(); i++) {
      if (buyOrders.at(i) == order) {
        buyOrders.erase(buyOrders.begin() + i);
        return true;
      }
    }
  } else {
    for (int i = 0; i < sellOrders.size(); i++) {
      if (sellOrders.at(i) == order) {
        sellOrders.erase(sellOrders.begin() + i);
        return true;
      }
    }
  }
  return false;
}

void Stock::matchOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for(Order* sellOrder : sellOrders) {
      if (sellOrder->match(order)) {
        if(sellOrder->isFilled()) {
          sellOrders.erase(sellOrders.begin());
        }
        if(order->isFilled()) {
          return;
        }
      }
      else {
        insertOrder(order);
      }
    }
  } else {
    for(Order* buyOrder : buyOrders) {
      if (buyOrder->match(order)) {
        if(buyOrder->isFilled()) {
          buyOrders.erase(buyOrders.begin());
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
}

std::vector<Order*> Stock::getOrders(bool isBuyOrder) {
  if (isBuyOrder) {
    return buyOrders;
  } else {
    return sellOrders;
  }
}

void Stock::display() {
  std::cout << name << " - " << price << std::endl;
}