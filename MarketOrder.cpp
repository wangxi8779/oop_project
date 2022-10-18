#include "MarketOrder.h"

MarketOrder::MarketOrder(Stock* stock, int quantity, bool isBuyOrder) {
  this->stock = stock;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool MarketOrder::match(Order* order)
{
  int transactionQuantity = 0;
  double transactionPrice = 0;
  if (isBuyOrder)
  {
    if (bidPrice() >= order->bidPrice())
    {
      // decide the transaction quantity based on order quantity
      if (getUnfilledQuantity() >= order->getUnfilledQuantity())
      {
        transactionQuantity = order->getUnfilledQuantity();
      }
      else
      {
        transactionQuantity = getUnfilledQuantity();
      }
      // decide the transaction price based on order type and bid price
      if (order->isMarketOrder())
      {
        // if both market orders, use current stock price
        transactionPrice = stock->getPrice();
      }
      else
      {
        // if sell order is limited, use the bid price
        transactionPrice = order->bidPrice();
      }

      // save the transaction record for both of buy and sell orders
      addTransaction(Transaction(transactionPrice, transactionQuantity));
      order->addTransaction(Transaction(transactionPrice, transactionQuantity));

      // adjust the stock price
      stock->setPrice(transactionPrice);
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    if (bidPrice() <= order->bidPrice())
    {
      if (getUnfilledQuantity() >= order->getUnfilledQuantity())
      {
        transactionQuantity = order->getUnfilledQuantity();
      }
      else
      {
        transactionQuantity = getUnfilledQuantity();
      }
      if (order->isMarketOrder())
      {
        transactionPrice = stock->getPrice();
      }
      else
      {
        transactionPrice = order->bidPrice();
      }
      addTransaction(Transaction(transactionPrice, transactionQuantity));
      order->addTransaction(Transaction(transactionPrice, transactionQuantity));
      stock->setPrice(transactionPrice);
      return true;
    }
    else
    {
      return false;
    }
  }
}

double MarketOrder::bidPrice() {
  // fake bid price, for compare/match purpose
  if(isBuyOrder) {
    return 100000000;
  } else {
    return -1;
  }
}

bool MarketOrder::isMarketOrder() {
  return true;
}

MarketOrder::~MarketOrder() {}
