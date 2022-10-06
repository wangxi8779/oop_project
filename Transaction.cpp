#include "Transaction.h"
#include <iostream>
#include <string>
Transaction::Transaction(){
  info[0] = 0;
  info[1] = 0;
  //info[0] == price 
  //info[1] == quality
}
Transaction::Transaction(double price,double quality){
  info[0] = price;
  info[1] = quality;
}
//for the display function I just outputed the values as idk how the ui would work please let me know if thats not the case 
double* Transaction::display(){
  return info;
};
Transaction::~Transaction(){}

