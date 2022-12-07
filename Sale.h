#ifndef SALE_H
#define SALE_H

#include <string>
#include "Date.h"

using namespace std;

class Sale{
public:
    Date datePurchased;
    int customer;
    string item;
    double price;
    int quantity;
    Sale();
    Sale(Date datePurchased, int customer, string item, double price, int quantity);
    bool isDate(Date date);
    int getCustomer();
};

#endif // SALE_H
