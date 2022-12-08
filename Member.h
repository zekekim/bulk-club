#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "Date.h"

using namespace std;

const double rebateRate = 0.02;
const double taxRate = 7.75;

class Member{
public:
    string name;
    int number;
    int type;
    Date expiration;
    double total;
    double rebate;
    Member();
    Member(string name, int number, int type, Date expiration, double total, double rebate);
    bool isName(string name);
    bool isNumber(int number);
    double getRebate();
    Date getExpiration();
    double getTotalRevenue();
};

#endif // MEMBER_H
