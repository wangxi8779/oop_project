#include "Stock.h"

double Stock::get_price() { return price; }
bool Stock::addOrder(Order* order) {
  orders.push_back(order);
  matchOrder();
  return true;
}
bool Stock::removeOrder(Order* order) {
  for (int i = 0; i < orders.size(); i++) {
    if (orders.at(i) == order) {
      orders.erase(orders.begin() + i);
      return true;
    }
  }
  return false;
}
void Stock::matchOrder() {
  // TODO:
  // loop all orders and find matched buy and sell orders
  // also create transactions and update the stock price
}
