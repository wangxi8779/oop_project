#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

#include "Transaction.h"

class Order {
 private:
  bool isBuyOrder;
  std::string status;
  int quantity;
  std::vector<Transaction> transactions;

 public:
  Order(double, int, bool);
  bool match(Order*);
  void cancel();
  bool addTransaction(Transaction);
  bool isFilled();
  bool getIsBuyOrder();
};
#endif
