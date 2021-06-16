////
//// Created by cheng on 2021/3/8.
////

#include "Manager.h"
#include <iomanip>

int Manager::date = 0;
int Manager::invoice = 1000;
list<Customer> Manager::customerList{};

bool Manager::checkOrder(Order &o) {
    if(o.date == Manager::date)return true;
    else return false;
}

int Manager::handleInput(string &i) {
    switch(i[0]){
        case 'C':
        {
            try{
                int newCustomerNum = stoi(i.substr(1,4));
                if(newCustomerNum < 0) throw "Error occurs during definition of a new customer's number";
                string newCustomerName = i.substr(5,40);
                Customer newCustomer(newCustomerNum,newCustomerName);
                Manager::customerList.push_back(newCustomer);
                cout << "OP: customer ";
                cout << setfill('0') << setw(4) << newCustomer.number;
                cout << " added" << endl;
                break;
            }catch(char* ex){
                cerr << ex << endl;
                exit(1);
            }
        }
        case 'S':
        {
            try{
                char orderType = i[9];
                int orderCustomNum = stoi(i.substr(10,4));
                if(orderCustomNum < 0) throw "Error occurs during definition of a new order's target client number";
                int orderQuantity = stoi(i.substr(14,3));
                if(orderQuantity < 0) throw "Error occurs during definition of a new order's quantity";
                int orderDate = stoi(i.substr(1,8));
                if(orderDate < 0) throw "Error occurs during definition of a new order's date";
                Order newOrder(orderType,orderCustomNum,orderQuantity,orderDate);
                if(Manager::date == 0) Manager::date = orderDate;
                if(Manager::checkOrder(newOrder)){  // addFromOrder will check if the numbers of the order & customer match, so only need to check date
                    for(Customer &c: Manager::customerList) {
                        if(c.addFromOrder(newOrder, Manager::invoice, Manager::date)) Manager::invoice += 1; // returns if an express order has been shipped
                    }
                }else cout << "an order with an unmatched date has been ignored. Order details: order type " << orderType << "; ordered customer number " << orderCustomNum << "; order quantity " << orderQuantity << "; order date " << orderDate << endl;
                break;
            }catch(const char* ex){
                cerr << ex << endl;
                exit(1);
            }
        }
        case 'E':
        {
            try{
                int endDate = stoi(i.substr(1,8));
                if(Manager::date == endDate){
                    cout << "end of day " << Manager::date << ": " << endl;
                    for(Customer &c:Manager::customerList){
                        if(c.quantity > 0){
                            c.ship(Manager::invoice, Manager::date);
                            Manager::invoice += 1;
                        }
                    }

                    // handling current date changes
                    int currentYear = Manager::date / 10000;
                    int currentMonth = Manager::date % 10000 / 100;
                    int currentDate = Manager::date % 10000 % 100;

                    switch(currentMonth){  // get month
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 8:
                        case 10:
                            if(currentDate + 1 > 31) Manager::date = Manager::date + 100 - 31;
                            else Manager::date += 1;
                            break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            if(currentDate + 1 > 30) Manager::date = Manager::date + 100 - 30;
                            else Manager::date += 1;
                            break;
                        case 2:
                            if((currentYear % 4 == 0 && currentYear % 100 != 0) || currentYear % 400 == 0){
                                if(currentDate + 1 > 29) Manager::date = Manager::date + 100 - 29;
                                else Manager::date += 1;
                            }else{
                                if(currentDate + 1 > 28) Manager::date = Manager::date + 100 - 28;
                                else Manager::date += 1;
                            }
                            break;
                        case 12:
                            if(currentDate + 1 > 31) Manager::date = Manager::date + 10000 - 1231;
                            else Manager::date += 1;
                        default:
                            cerr << "an error occurs while applying date changes, current date is: " << Manager::date <<endl;
                            exit(1);
                    }
                }else{
                    cout << "an invalid end-day operation with date " << endDate << " has been ignored" << endl;
                }
                break;
            }catch(const char* ex){
                cerr << ex << endl;
                exit(1);
            }
        }
        default: cout << "unrecognized operation. Begins with prefix " << i[0] << endl;

    }
    return 0;
}

