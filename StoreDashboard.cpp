#include "StoreDashboard.h"

StoreDashboard::StoreDashboard()
{
}

void StoreDashboard::addSale(Sale sale)
{
    sales.push_back(sale);
}

void StoreDashboard::addItem(bool isAdmin, Item item)
{
    if (!isAdmin)
    {
        return;
    }
    inventory.push_back(item);
}

void StoreDashboard::updateItem(bool isAdmin, string item, double price)
{
    if (!isAdmin)
    {
        return;
    }
    for (auto i = inventory.begin(); i != inventory.end(); ++i)
    {
        if (i->isName(item))
        {
            i->changePrice(price);
        }
    }
}
void StoreDashboard::deleteItem(bool isAdmin, string item)
{
    if(!isAdmin)
    {
        return;
    }
    for (auto i = inventory.begin(); i != inventory.end(); ++i)
    {
        if (i->isName(item))
        {
            inventory.erase(i);
        }
    }
}
Item StoreDashboard::findItem(string item)
{
    for (auto i = inventory.begin(); i != inventory.end(); ++i)
    {
        if (i->isName(item))
        {
            return *i;
        }
    }
    return Item();
}
void StoreDashboard::addMember(bool isAdmin, Member member)
{
    if (isAdmin)
    {
        return;
    }
    members.push_back(member);
}
void StoreDashboard::deleteMember(bool isAdmin, int member)
{
    if (isAdmin)
    {
        return;
    }
    for (auto i = members.begin(); i != members.end(); ++i)
    {
        if (i->isNumber(member))
        {
            members.erase(i);
        }
    }
}

void StoreDashboard::readDayFile(string fileName)
{
//    4/1/2021
//    67890
//    1 gallon milk
//    6.49
//    20
    ifstream inFile;
    inFile.open(fileName.c_str());
    int index = 0;
    Date date;
    int memberNumber;
    string name;
    double price;
    int quantity;
    while(!inFile.eof())
    {
        if (index == 0)
        {
            string month;
            string day;
            string year;
            getline(inFile, month, '/');
            getline(inFile, day, '/');
            getline(inFile, year);
            date = Date{stoi(month), stoi(day), stoi(year)};
            index++;
        }
        else if (index == 1)
        {
            string memNum;
            getline(inFile, memNum);
            memberNumber = stoi(memNum);
            index++;
        }
        else if (index == 2)
        {
            getline(inFile, name);
            index++;
        }
        else if (index == 3)
        {
            string tempPrice;
            getline(inFile, tempPrice);
            price = stod(tempPrice);
            index++;
        }
        else if (index == 4)
        {
            string tempQuant;
            getline(inFile, tempQuant);
            quantity = stoi(tempQuant);
            Sale sale = Sale(date, memberNumber, name, price, quantity);
            addSale(sale);
            index = 0;
        }

    }
    inFile.close();
}

void StoreDashboard::readMemberFile()
{
//    Fred Frugal
//    12897
//    Executive
//    12/15/2021
    ifstream inFile;
    inFile.open("warehouse-shoppers.txt");
    int index = 0;
    string name;
    int id;
    int type;
    Date date;
    while(!inFile.eof())
    {
        if (index == 0)
        {
            getline(inFile, name);
            index++;
        }
        else if (index == 1)
        {
            string tempId;
            getline(inFile, tempId);
            id = stoi(tempId);
            index++;
        }
        else if (index == 2)
        {
            string tempType;
            getline(inFile, tempType);
            if (tempType == "Executive")
            {
                type = 1;
            }
            else
            {
                type = 0;
            }
            index++;
        }
        else if (index == 3)
        {
            string month;
            string day;
            string year;
            getline(inFile, month, '/');
            getline(inFile, day, '/');
            getline(inFile, year);
            date = Date{stoi(month), stoi(day), stoi(year)};
            Member member = Member(name, id, type, date, 0, 0);
            addMember(true, member);
            index = 0;
        }
    }
}

