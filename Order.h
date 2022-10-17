#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

#include "Stock.h"
#include "Transaction.h"

class Order {
 protected:
  Stock* stock;
  bool isBuyOrder;
  std::string status;
  int quantity;
  int filledQuantity;
  std::vector<Transaction> transactions;

 public:
  Order(){};
  Order(Stock* stock, double, int, bool);
  virtual bool match(Order*);
  virtual double bidPrice();
  void cancel();
  std::vector<Transaction> getTransactions();
  void addTransaction(Transaction);
  bool isFilled();
  bool getIsBuyOrder();
  bool isMarketOrder();
  int getQuantity();
  int getFilledQuantity();
  int getUnfilledQuantity();
  std::string getStatus();
  ~Order();
};
#endif
