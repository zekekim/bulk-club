#ifndef STOREDASHBOARD_H
#define STOREDASHBOARD_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Date.h"
#include "Item.h"
#include "Member.h"
#include "Sale.h"
#include <fstream>
#include <sstream>

using namespace std;

class StoreDashboard{
public:
    vector<Item> inventory;
    vector<Member> members;
    vector<Sale> sales;
    StoreDashboard();
    void addSale(Sale sale);
    void addItem(bool isAdmin, Item item);
    void updateItem(bool isAdmin, string item, double price);
    void deleteItem(bool isAdmin, string item);
    Item findItem(string item);
    void addMember(bool isAdmin, Member member);
    void deleteMember(bool isAdmin, int member);
    void readDayFile(string fileName);
    void readMemberFile();
};

#endif // STOREDASHBOARD_H
