#ifndef STOREDASHBOARD_H
#define STOREDASHBOARD_H

#include <iostream>
#include <vector>
#include "Date.h"
#include "Item.h"
#include "Member.h"
#include "Sale.h"

using namespace std;

class StoreDashboard{
    vector<Item> inventory;
    vector<Member> members;
    vector<Sale> sales;
public:
    StoreDashboard();
    void addSale(Sale sale);
    void addItem(bool isAdmin, Item item);
    void updateItem(bool isAdmin, string item, double price);
    void deleteItem(bool isAdmin, string item);
    Item findItem(string item);
    void addMember(bool isAdmin, Member member);
    void deleteMember(bool isAdmin, int member);

};

#endif // STOREDASHBOARD_H
