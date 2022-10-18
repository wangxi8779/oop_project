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
 //defult constructor
  Transaction(double, int);
 //constructor
  int getQuantity();
 //returns quantity value
  double getPrice();
 //returns price value
  void display();
 //prints both values
  ~Transaction();
 //deconstructor
};
#endif
