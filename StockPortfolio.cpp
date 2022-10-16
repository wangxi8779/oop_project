#include <iostream>
#include "StockPortfolio.h"

StockPortfolio::StockPortfolio() {}

StockPortfolio::StockPortfolio(Stock* stock) {
  this->stock = stock;
  this->averagePrice = 0;
  this->gain = 0;
  this->quantity = 0;
}

StockPortfolio::StockPortfolio(Stock* stock, int quantity) {
  this->stock = stock;
  this->averagePrice = 0;
  this->gain = 0;
  this->quantity = quantity;
}

bool StockPortfolio::placeOrder(Order* order) {
  orders.push_back(order);
  stock->matchOrder(order);
  return true;
}
bool StockPortfolio::cancelOrder(Order* order) {
  for(int i = 0; i < orders.size(); i++) {
    if (orders.at(i) == order) {
      if (order->isFilled()) {
        std::cout << "This order is filled, cannot cancel." << std::endl;
        return false;
      } else {
        order->cancel();
        return true;
      }
    }
  }
  std::cout << "This order is not found, cannot cancel." << std::endl;
  return false;
}

Stock* StockPortfolio::getStock() {
  return stock;
}

int StockPortfolio::getQuantity() {
  return quantity;
}

void StockPortfolio::display() {
  refresh();
  std::cout << "average price - " << averagePrice << std::endl;
  std::cout << "quantity - " << quantity << std::endl;
  std::cout << "gain/loss - " << gain << std::endl;
}

void StockPortfolio::refresh() {
  double totalPaid = 0;
  int totalQuantity = 0;
  for(Order* order : orders) {
    bool isBuyOrder = order->getIsBuyOrder();
    for(Transaction transaction : order->getTransactions()) {
      if (isBuyOrder) {
        totalQuantity += transaction.getQuantity();
        totalPaid += transaction.getPrice() * transaction.getQuantity();
      } else {
        totalQuantity -= transaction.getQuantity();
        totalPaid -= transaction.getPrice() * transaction.getQuantity();
      }
    }
  }
  if (totalQuantity > 0) {
    averagePrice = totalPaid / totalQuantity;
  }
  quantity = totalQuantity;
  gain = stock->getPrice() * quantity - totalPaid;
}

