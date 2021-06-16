//
// Created by cheng on 2021/3/8.
//

#include "Order.h"
Order::Order(char type, int customNum, int quantity, int date) {
   this->type = type;
   this->customerNum = customNum;
   this->quantity = quantity;
   this->date = date;
}