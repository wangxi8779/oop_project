#include <iostream>
#include "Stock.h"
#include "Order.h"

Stock::Stock(std::string name, double price) {
  this->name = name;
  this->price = price;
}

double Stock::getPrice() { return price; }

void Stock::setPrice(double price) { this->price = price; }

void Stock::insertOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for(int i = 0; i < buyOrders.size(); i++) {
      if (order->bidPrice() > buyOrders.at(i)->bidPrice()) {
        buyOrders.insert(buyOrders.begin() + i, order);
        return;
      }
    }
    buyOrders.push_back(order);
  } else {
    for(int i = 0; i < sellOrders.size(); i++) {
      if (order->bidPrice() < buyOrders.at(i)->bidPrice()) {
        sellOrders.insert(sellOrders.begin() + i, order);
        return;
      }
    }
    sellOrders.push_back(order);
  }
}

void Stock::removeOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for (int i = 0; i < buyOrders.size(); i++) {
      if (buyOrders.at(i) == order) {
        buyOrders.erase(buyOrders.begin() + i);
        return;
      }
    }
  } else {
    for (int i = 0; i < sellOrders.size(); i++) {
      if (sellOrders.at(i) == order) {
        sellOrders.erase(sellOrders.begin() + i);
        return;
      }
    }
  }
}

void Stock::matchOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for(Order* sellOrder : sellOrders) {
      if (order->match(sellOrder)) {
        // if(sellOrder->isFilled()) {
        //   sellOrders.erase(sellOrders.begin());
        // }
        if(order->isFilled()) {
          return;
        }
      }
      else {
        insertOrder(order);
        return;
      }
    }
  } else {
    for(Order* buyOrder : buyOrders) {
      if (order->match(buyOrder)) {
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