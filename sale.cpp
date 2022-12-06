#include "Sale.h"

Sale::Sale():datePurchased(Date{"ERROR",0,0}), customer(0), item("Error"), quantity(0)
{
}

Sale::Sale(Date datePurchased, int customer, string item, int quantity):datePurchased(datePurchased),customer(customer),item(item),quantity(quantity)
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
