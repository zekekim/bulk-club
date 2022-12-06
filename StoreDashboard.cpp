#include "StoreDashboard.h"

StoreDashboard::StoreDashboard()
{
}

void StoreDashboard::addSale(Sale sale)
{
    sales.emplace_back(sale);
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
    if(!isAdmin)
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

