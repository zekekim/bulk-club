#include "managemembers.h"
#include "ui_managemembers.h"
#include "StoreDashboard.h"

QString name;
QString number;
QString type = "Regular";

ManageMembers::ManageMembers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageMembers)
{
    ui->setupUi(this);

}

ManageMembers::~ManageMembers()
{
    delete ui;
}

void ManageMembers::on_member_name_editingFinished()
{
    name = ui->member_name->text();
}


void ManageMembers::on_member_number_editingFinished()
{
    number = ui->member_number->text();
}


void ManageMembers::on_type_currentIndexChanged(int index)
{
    if (index == 0)
    {
        type = "Regular";
    }
    else
    {
        type = "Executive";
    }
}


void ManageMembers::on_add_member_clicked()
{
    StoreDashboard *store = store->getInstance();
    Member newMember = Member(name.toStdString(), number.toInt(), type.toStdString(), Date{12,22,2023}, 0.0, 0.0);
    store->addMember(true, newMember);
}


void ManageMembers::on_pushButton_2_clicked()
{
    StoreDashboard *store= store->getInstance();
    vector<Member> *members = store->members;
    vector<Sale> *sales = store->sales;
    for (auto i = members->begin(); i != members->end();)
    {
        if (i->isNumber(number.toInt()))
        {
            members->erase(i);
        }
        else
        {
            ++i;
        }
    }
    for (auto i = sales->begin(); i != sales->end();)
    {
        if (i->customer == number.toInt())
        {
            sales->erase(i);
        }
        else
        {
            ++i;
        }
    }
}

