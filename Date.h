#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

struct Date
{
    string month;
    int date;
    int year;
};

bool operator==(const Date& lhs, const Date& rhs)
{
    return (lhs.month == rhs.month) && (lhs.date == rhs.date) && (lhs.year == rhs.year);
}

#endif // DATE_H
