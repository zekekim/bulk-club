#ifndef SALE_H
#define SALE_H

#include <string>
#include "Date.h"

using namespace std;

class Sale{
    Date datePurchased;
    int customer;
    string item;
    int quantity;
public:
    Sale();
    Sale(Date datePurchased, int customer, string item, int quantity);
    bool isDate(Date date);
    int getCustomer();
};

#endif // SALE_H
