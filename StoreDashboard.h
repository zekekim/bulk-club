#ifndef STOREDASHBOARD_H
#define STOREDASHBOARD_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Item.h"
#include "Member.h"
#include "Sale.h"
#include <fstream>
#include <sstream>
#include <QString>

using namespace std;

class StoreDashboard{
    StoreDashboard();
public:
    static StoreDashboard *instance;
    vector<Item> *inventory;
    vector<Member> *members;
    vector<Sale> *sales;
    int admin = 0;
    static StoreDashboard *getInstance() {
      if (!instance)
      instance = new StoreDashboard;
      return instance;
    }

    void addSale(Sale sale);
    void addItem(bool isAdmin, Item item);
    void updateItem(bool isAdmin, string item, double price);
    void deleteItem(bool isAdmin, string item);
    double getRevenueTotal(vector<Sale> sales);
    Item *findItem(string item);
    Member *findMember(int member);
    double getMembersTotal(vector<Member> members);
    void addMember(bool isAdmin, Member member);
    void deleteMember(bool isAdmin, int member);
    int getExecutiveCount();
    int getRegularCount();
    void readDayFile(QString fileName);
    void readMemberFile();
};

#endif // STOREDASHBOARD_H
