#ifndef ADMIN_H
#define ADMIN_H
#include <string>

#include "Account.h"

class Admin : public Account {
 public:
  Admin(std::string password, std::string name, std::string phone,
          std::string email, std::string status):Account(password, name, phone, email, status){};
  bool block(Account);
  bool unblock(Account);
};

#endif
