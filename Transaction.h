//if there is anything that you would want to change 
//or if there is a problem with my code please let me know in the group chat
#ifndef TRANSACTION
#define TRANSACTION
#include <iostream>
#include <string>
class Transaction{
public:
//to make sure that both values can be outputed by the one function they are both stored in one array
double info[];
Transaction();
Transaction(double price,double quality);
~Transaction();
double* display();
};
#endif