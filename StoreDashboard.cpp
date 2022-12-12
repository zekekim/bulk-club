#include "StoreDashboard.h"
#include <QDebug>
#include <QFile>

StoreDashboard::StoreDashboard()
{
    inventory = new vector<Item>;
    sales = new vector<Sale>;
    members = new vector<Member>;
}



void StoreDashboard::updateItem(bool isAdmin, string item, double price)
{
    if (!isAdmin)
    {
        return;
    }
    for (auto i = inventory->begin(); i != inventory->end(); ++i)
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
    for (auto i = inventory->begin(); i != inventory->end(); ++i)
    {
        if (i->isName(item))
        {
            inventory->erase(i);
        }
    }
}
Item* StoreDashboard::findItem(string item)
{
    for (auto i = inventory->begin(); i != inventory->end(); ++i)
    {
        if (i->name == item)
        {
            return &*i;
        }
    }
    return NULL;
}

void StoreDashboard::addItem(bool isAdmin, Item item)
{
    if (!isAdmin)
    {
        return;
    }
    if (findItem(item.name) != NULL)
    {
        findItem(item.name)->quantity += item.quantity;
    }
    else
    {
        inventory->push_back(item);
    }
}



double StoreDashboard::getRevenueTotal(vector<Sale> sales)
{
    double total = 0.0;
    for (auto i = sales.begin(); i != sales.end(); ++i)
    {
        double item = i->price * i->quantity;
        total += item;
    }
    return total;
}

double StoreDashboard::getMembersTotal(vector<Member> members)
{
    double total = 0.0;
    for (auto i = members.begin(); i != members.end(); ++i)
    {
        total += i->total;
    }
    return total;
}

void StoreDashboard::addMember(bool isAdmin, Member member)
{
    if (isAdmin)
    {
        return;
    }
    members->push_back(member);
}

Member* StoreDashboard::findMember(int member)
{
    for (auto i = members->begin(); i != members->end(); ++i)
    {
        if (i->isNumber(member))
        {
            return &*i;
        }
    }
    return NULL;
}

void StoreDashboard::deleteMember(bool isAdmin, int member)
{
    if (isAdmin)
    {
        return;
    }
    for (auto i = members->begin(); i != members->end(); ++i)
    {
        if (i->isNumber(member))
        {
            members->erase(i);
        }
    }
}
void StoreDashboard::addSale(Sale sale)
{
    int customer = sale.customer;
    Member *member = findMember(customer);
    sales->push_back(sale);
    member->addPurchase(sale.price * sale.quantity);
}

int StoreDashboard::getExecutiveCount()
{
    int count = 0;
    for (auto i = members->begin(); i != members->end(); ++i)
    {
        if (i->type == "Executive")
        {
            count++;
        }
    }
    return count;
}

int StoreDashboard::getRegularCount()
{
    return members->size() - getExecutiveCount();
}

void StoreDashboard::readDayFile(QString fileName)
{
//    4/1/2021
//    67890
//    1 gallon milk
//    6.49
//    20
    QFile inFile(fileName);

    int index = 0;
    Date date;
    int memberNumber;
    string name;
    double price;
    int quantity;
    if (inFile.open(QIODevice::ReadOnly))
    {
        while(!inFile.atEnd())
        {
            if (index == 0)
            {

                QString line = inFile.readLine().replace("\r\n", "");
                if (line == " ")
                {
                    return;
                }
                QStringList list = line.split("/");
                int month = stoi(list[0].toStdString());
                int day = stoi(list[1].toStdString());
                int year = stoi(list[2].toStdString());
                date = Date{month,day ,year};
                index++;
            }
            else if (index == 1)
            {
                QString line = inFile.readLine().replace("\r\n", "");
                memberNumber = stoi(line.toStdString());
                index++;
            }
            else if (index == 2)
            {
                QString line = inFile.readLine().replace("\r\n", "");
                name = line.toStdString();
                index++;
            }
            else if (index == 3)
            {
                QString line = inFile.readLine().replace("\t\r\n", "").replace("\r\n", "");
                price = stod(line.toStdString());
                index++;
            }
            else
            {
                QString line = inFile.readLine().replace("\r\n", "");
                quantity = stoi(line.toStdString());
                Sale sale = Sale(date, memberNumber, name, price, quantity);
                addSale(sale);
                Item item = Item(name, quantity, price * quantity, price);
                addItem(true,item);
                qDebug() << "SALE: " << QString::fromStdString(findMember(memberNumber)->name);
                index = 0;
            }

        }
    }
    else{
        qDebug() << "NO!!";
    }
        inFile.close();

}

void StoreDashboard::readMemberFile()
{
//    Fred Frugal
//    12897
//    Executive
//    12/15/2021
    QFile inFile(":/txt/warehouse-shoppers.txt");

    int index = 0;
    string name;
    int id;
    string type;
    Date date;
    if (inFile.open(QIODevice::ReadOnly))
    {
        while(!inFile.atEnd())
        {
            if (index == 0)
            {
                name = inFile.readLine().replace("\r\n", "");
                index++;
            }
            else if (index == 1)
            {
                string tempId;
                tempId = inFile.readLine().replace("\r\n", "");
                id = stoi(tempId);
                index++;
            }
            else if (index == 2)
            {
                string tempType;
                type = inFile.readLine().replace("\r\n", "");
                index++;
            }
            else
            {
                QString line = inFile.readLine();
                if (line == " ")
                {
                    return;
                }
                QStringList list = line.split("/");
                int month = stoi(list[0].toStdString());
                int day = stoi(list[1].toStdString());
                int year = stoi(list[2].replace("\r\n", "").toStdString());
                date = Date{month,day ,year};
                members->push_back(Member(name,id,type,date,0.0,0.0));
                qDebug() << "MEMBER: " << QString::fromStdString(name);
                qDebug() << "TYPE" << QString::fromStdString(type);
                index = 0;
            }
        }
    }
}



