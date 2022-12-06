#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{
    string name;
    int quantity;
    double revenue;
    double price;
public:
    Item();
    Item(string name, int quantity, double revenue, double price);
    bool isName(string name);
    void changePrice(double price);
};

#endif // ITEM_H
