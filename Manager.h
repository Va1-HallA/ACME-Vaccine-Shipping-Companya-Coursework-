//
// Created by cheng on 2021/3/8.
//

#ifndef UNTITLED1_MANAGER_H
#define UNTITLED1_MANAGER_H


#include "Order.h"
#include "Customer.h"
#include <list>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Manager {
    static int date;
    static int invoice;
    static list<Customer> customerList;
    static bool checkOrder(Order&);
public:
    static int handleInput(string&);
};


#endif //UNTITLED1_MANAGER_H
