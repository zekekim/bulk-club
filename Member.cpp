#include "Member.h"

Member::Member():name(""),number(0),type(0),expiration(Date{0,0,0}),total(0.0),rebate(0.0)
{
}

Member::Member(string name, int number, int type, Date expiration, double total, double rebate):name(name),number(number),type(type),expiration(expiration),total(total),rebate(rebate)
{
}


bool Member::isName(string name)
{
    return this->name == name;
}

bool Member::isNumber(int number)
{
    return this->number == number;
}

double Member::getRebate()
{
    this->rebate = rebateRate * this->total;
    return rebate;
}

Date Member::getExpiration()
{
    return expiration;
}

double Member::getTotalRevenue() {
    return (1.0 + taxRate) * total;
}
