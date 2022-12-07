#include "Sale.h"

Sale::Sale():datePurchased(Date{0,0,0}), customer(0), item(""), price(0.0), quantity(0)
{
}

Sale::Sale(Date datePurchased, int customer, string item, double price, int quantity):datePurchased(datePurchased),customer(customer),item(item),price(price), quantity(quantity)
{
}

bool Sale::isDate(Date date)
{
    return datePurchased == date;
}

int Sale::getCustomer()
{
    return customer;
}
