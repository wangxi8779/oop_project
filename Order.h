#ifndef ORDER_H;
#define ORDER_H ;
#include <string>
#include <vector>

#include "Transaction.h"

class Order {
 private:
  bool is_buy_order;
  std::string status;
  int quantity;
  std::vector<Transaction> transactions;

 public:
  void match();
  bool addTransaction(Transaction);
};
#endif
