//
// Created by cheng on 2021/3/8.
//

#ifndef UNTITLED1_CUSTOMER_H
#define UNTITLED1_CUSTOMER_H

#include <string>
#include "Order.h"
using namespace std;

class Customer {
    int number;
    int quantity;
    string name;
    void ship(int, int);
    void receive(int, int, int) const;
    friend class Manager;
public:
Customer(int, string);
bool addFromOrder(Order&, int, int); // check if the order matches the customer number first, returns if an express order has been added
};


#endif //UNTITLED1_CUSTOMER_H
