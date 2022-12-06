#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "Date.h"

using namespace std;

class Member{
    string name;
    int number;
    int type;
    Date expiration;
    double total;
    double rebate;

public:
    Member();
    Member(string name, int number, int type, Date expiration, double total, double rebate);
    bool isName(string name);
    bool isNumber(int number);
    double getRebate();
    Date getExpiration();
};

#endif // MEMBER_H
