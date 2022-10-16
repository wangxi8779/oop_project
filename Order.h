#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

#include "Transaction.h"

class Order {
 protected:
  bool isBuyOrder;
  std::string status;
  int quantity;
  std::vector<Transaction> transactions;

 public:
  Order(double, int, bool);
  virtual bool match(Order*);
  virtual double bidPrice();
  void cancel();
  bool addTransaction(Transaction);
  bool isFilled();
  bool getIsBuyOrder();
  int getQuantity();
};
#endif
