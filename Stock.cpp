#include "Stock.h"

#include <iostream>

#include "Order.h"

Stock::Stock(std::string name, double price) {
  this->name = name;
  this->price = price;
}

double Stock::getPrice() { return price; }

void Stock::setPrice(double price) { this->price = price; }

// the pending buy/sell orders need to be sorted
// this method helps to insert order into right place
void Stock::insertOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for (int i = 0; i < buyOrders.size(); i++) {
      // buy orders -- sort by price high to low
      if (order->bidPrice() > buyOrders.at(i)->bidPrice()) {
        buyOrders.insert(buyOrders.begin() + i, order);
        return;
      }
    }
    buyOrders.push_back(order);
  } else {
    for (int i = 0; i < sellOrders.size(); i++) {
      // sell orders -- sort by price low to high
      if (order->bidPrice() < buyOrders.at(i)->bidPrice()) {
        sellOrders.insert(sellOrders.begin() + i, order);
        return;
      }
    }
    sellOrders.push_back(order);
  }
}

void Stock::matchOrder(Order* order) {
  if (order->getIsBuyOrder()) {
    for (Order* sellOrder : sellOrders) {
      if (order->match(sellOrder)) {
        if (order->isFilled()) {
          // if order got filled, exit matching
          // if not, try to match the next best bid
          break;
        }
      } else {
        // if not fully filled, insert into queue
        insertOrder(order);
        break;
      }
    }
  } else {
    for (Order* buyOrder : buyOrders) {
      if (order->match(buyOrder)) {
        if (order->isFilled()) {
          break;
        }
      } else {
        // if not fully filled, insert into queue
        insertOrder(order);
        break;
      }
    }
  }

  // refresh order queues, remove filled orders
  std::vector<Order*> orders;
  if (order->getIsBuyOrder()) {
    for (int i = 0; i < sellOrders.size(); i++) {
      if (sellOrders.at(i)->getStatus() != "filled") {
        orders.push_back(sellOrders.at(i));
      }
    }
    sellOrders = orders;
  } else {
    for (int i = 0; i < buyOrders.size(); i++) {
      if (buyOrders.at(i)->getStatus() != "filled") {
        orders.push_back(buyOrders.at(i));
      }
    }
    buyOrders = orders;
  }
}

std::vector<Order*> Stock::getOrders(bool isBuyOrder) {
  if (isBuyOrder) {
    return buyOrders;
  } else {
    return sellOrders;
  }
}

void Stock::display() { std::cout << name << " - " << price << std::endl; }

Stock::~Stock() {
  for (Order* order : buyOrders) {
    delete order;
  }
  buyOrders.clear();
  for (Order* order : sellOrders) {
    delete order;
  }
  sellOrders.clear();
}
