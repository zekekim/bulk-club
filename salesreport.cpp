#include "salesreport.h"
#include "ui_salesreport.h"
#include "StoreDashboard.h"
#include <vector>
#include <QTableWidget>
#include <QTableWidgetItem>


SalesReport::SalesReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);
    StoreDashboard *store = store->getInstance();
    vector<Sale> *sales = store->sales;
    displayTable(*sales, store);
}

SalesReport::~SalesReport()
{
    delete ui;
}


void SalesReport::displayTable(vector<Sale> sales, StoreDashboard *store)
{
    QTableWidget *table = ui->tableWidget;
    table->setRowCount(std::size(sales));
    table->setColumnCount(5);
    table->setColumnWidth(2, 200);
    table->setHorizontalHeaderLabels({"Date", "Member", "Product", "Price", "Quantity"});
    qDebug() << std::size(sales);
    for (unsigned int i = 0; i < std::size(sales); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j==0)
            {
                QString date = QString::fromStdString(std::to_string(sales.at(i).datePurchased.month) + "/" + std::to_string(sales.at(i).datePurchased.date) + "/" + std::to_string(sales.at(i).datePurchased.year));
                QTableWidgetItem *item = new QTableWidgetItem(date);
                table->setItem(i, j, item);
            }
            if (j==1)
            {
                QString member = QString::fromStdString(std::to_string(sales.at(i).customer));
                QTableWidgetItem *item = new QTableWidgetItem(member);
                table->setItem(i,j,item);
            }
            if (j==2)
            {
                QString product = QString::fromStdString(sales.at(i).item);
                QTableWidgetItem *item = new QTableWidgetItem(product);
                table->setItem(i,j,item);
            }
            if (j==3)
            {
                QString price = QString::fromStdString(std::to_string(sales.at(i).price)).replace("0000","").insert(0,"$");
                QTableWidgetItem *item = new QTableWidgetItem(price);
                item->setTextAlignment(Qt::AlignRight);
                table->setItem(i,j,item);
            }
            if (j==4)
            {
                QString quantity = QString::fromStdString(std::to_string(sales.at(i).quantity));
                QTableWidgetItem *item = new QTableWidgetItem(quantity);
                item->setTextAlignment(Qt::AlignRight);
                table->setItem(i,j,item);
            }

        }
    }
    QString revenue = QString::fromStdString(to_string(store->getRevenueTotal())).replace("0000","");
    QString executiveCount = QString::fromStdString(to_string(store->getExecutiveCount()));
    QString regularCount = QString::fromStdString(to_string(store->getRegularCount()));
    ui->revenueCount->setText("$" + revenue);
    ui->executiveCount->setText(executiveCount);
    ui->regularCount->setText(regularCount);
}



void SalesReport::on_dateEdit_userDateChanged(const QDate &date)
{
    StoreDashboard *store = store->getInstance();
    vector<Sale> sales = *store->sales;
    int month = date.month();
    int day = date.day();
    int year = date.year();
    Date selectedDate{month,day,year};
    for (auto i = sales.begin(); i != sales.end(); ++i)
    {
        if (!i->isDate(selectedDate))
        {
            sales.erase(i);
        }
    }
    displayTable(sales, store);
}


void SalesReport::on_comboBox_currentIndexChanged(int index)
{
    StoreDashboard *store = store->getInstance();
    vector<Sale> sales = *store->sales;
    vector<Member> members = *store->members;
    for (auto i = sales.begin(); i != sales.end(); ++i)
    {
        if (!store->findMember(i->customer))
        {
            qDebug() << "ERROR";
        }
        else if ((store->findMember(i->customer)->type == "Executive"))
        {
            if (index == 2)
            {

                sales.erase(i);
            }
        }
        else if ((store->findMember(i->customer)->type == "Regular"))
        {
            if (index == 1)
            {
                sales.erase(i);
            }
        }
    }
    displayTable(sales, store);
}

