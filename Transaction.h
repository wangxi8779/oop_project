#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

class Transaction {
 private:
  double price;
  int quantity;

 public:
  Transaction();
  Transaction(double, int);
  int getQuantity();
  double getPrice();
  void display();
  ~Transaction();
};
#endif
