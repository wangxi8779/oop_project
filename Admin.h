#ifndef ADMIN_H
#define ADMIN_H
#include <string>

#include "Account.h"

class Admin : public Account {
 public:
  bool block(Account);
  bool unblock(Account);
};

#endif
