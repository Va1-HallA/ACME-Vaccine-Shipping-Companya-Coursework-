//
// Created by cheng on 2021/3/8.
//

#ifndef UNTITLED1_ORDER_H
#define UNTITLED1_ORDER_H


class Order {
    char type;  // 'N' = normal, 'X' = express
    int customerNum;
    int quantity;
    int date;
    friend class Customer;
    friend class Manager;
    Order(char, int, int, int);
};


#endif //UNTITLED1_ORDER_H
