//
// Created by cheng on 2021/3/8.
//

#include "Customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

Customer::Customer(int number, string name) {
    this->quantity = 0;
    this->number = number;
    this->name = move(name);
}

bool Customer::addFromOrder(Order &o, int invoice, int date) {
    if(o.customerNum == this->number){
        if(o.type == 'X'){
            this->quantity += o.quantity;
            cout << "OP: customer ";
            cout << setfill('0') << setw(4) << this->number;
            cout << ": EXPRESS order: quantity " << o.quantity <<endl;
            this->ship(invoice, date);
            return true;
        }else if(o.type == 'N'){
            this->quantity += o.quantity;
            cout << "OP: customer ";
            cout << setfill('0') << setw(4) << this->number;
            cout << ": normal order: quantity " << o.quantity <<endl;
        }else cout << "an order with unrecognized type of " << o.type << "has been ignored" << endl;
    }
    return false;
}

void Customer::ship(int invoice, int date) {
    cout << "OP: customer ";
    cout << setfill('0') << setw(4) << this->number;
    cout << " shipped quantity " << this->quantity << endl;
    this -> receive(invoice, this->quantity, date);
    this->quantity = 0;
}

void Customer::receive(int invoice, int shippedQuantity, int date) const {
    cout << "SC: customer ";
    cout << setfill('0') << setw(4) << this->number;
    cout << ": invoice " << invoice << ": date " << date << ": quantity " << shippedQuantity << endl;
}
