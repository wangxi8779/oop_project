#include "Order.h"
void Order::match() {

}
bool Order::addTransaction(Transaction transaction) {
  transactions.push_back(transaction);
  return true;
}
