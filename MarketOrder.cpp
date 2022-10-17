#include "MarketOrder.h"

MarketOrder::MarketOrder(Stock* stock, int quantity, bool isBuyOrder) {
  this->stock = stock;
  this->quantity = quantity;
  this->isBuyOrder = isBuyOrder;
  this->status = "pending";
}

bool MarketOrder::match(Order* order)
{
  int transaction_quantity = 0;
  double transaction_price = 0;
  if (isBuyOrder)
  {
    if (bidPrice() >= order->bidPrice())
    {
      // decide the transaction quantity based on order quantity
      if (getUnfilledQuantity() >= order->getUnfilledQuantity())
      {
        transaction_quantity = order->getUnfilledQuantity();
      }
      else
      {
        transaction_quantity = getUnfilledQuantity();
      }
      // decide the transaction price based on order type and bid price
      if (order->isMarketOrder())
      {
        // if both market orders, use current stock price
        transaction_price = stock->getPrice();
      }
      else
      {
        // if sell order is limited, use the bid price
        transaction_price = order->bidPrice();
      }

      // save the transaction record for both of buy and sell orders
      addTransaction(Transaction(transaction_price, transaction_quantity));
      order->addTransaction(Transaction(transaction_price, transaction_quantity));

      // adjust the stock price
      stock->setPrice(transaction_price);
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
        transaction_quantity = order->getUnfilledQuantity();
      }
      else
      {
        transaction_quantity = getUnfilledQuantity();
      }
      if (order->isMarketOrder())
      {
        transaction_price = stock->getPrice();
      }
      else
      {
        transaction_price = order->bidPrice();
      }
      addTransaction(Transaction(transaction_price, transaction_quantity));
      order->addTransaction(Transaction(transaction_price, transaction_quantity));
      stock->setPrice(transaction_price);
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
