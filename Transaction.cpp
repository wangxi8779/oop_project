#include "Transaction.h"
#include <iostream>
#include <string>
Transaction::Transaction(){
  price = 0;
  quantity = 0;
}
Transaction::Transaction(double price, int quantity){
  this->price = price;
  this->quantity = quantity;
}
//for the display function I just outputed the values as idk how the ui would work please let me know if thats not the case 
void Transaction::display(){
};

double Transaction::getPrice(){
  return price;
};

int Transaction::getQuantity(){
  return quantity;
};

Transaction::~Transaction(){}

