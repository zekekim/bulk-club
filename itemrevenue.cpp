#include "itemrevenue.h"
#include "ui_itemrevenue.h"
#include "StoreDashboard.h"

ItemRevenue::ItemRevenue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemRevenue)
{
    ui->setupUi(this);
}

ItemRevenue::~ItemRevenue()
{
    delete ui;
}

void ItemRevenue::on_lineEdit_editingFinished()
{
    ui->tableWidget->setRowCount(1);
    StoreDashboard *store = store->getInstance();
    QTableWidget *widget = ui->tableWidget;
    Item* item = store->findItem(ui->lineEdit->text().toStdString());
    qDebug() << item;
    if (item != NULL)
    {
        string name = item->name;
        QTableWidgetItem *cell0 = new QTableWidgetItem(QString::fromStdString(name));
        widget->setItem(0,0,cell0);
        int quantity = item->quantity;
        QTableWidgetItem *cell1 = new QTableWidgetItem(QString::number(quantity));
        widget->setItem(0,1,cell1);
        double revenue = item->revenue;
        QTableWidgetItem *cell2 = new QTableWidgetItem("$"+QString::number(revenue, 'f', 2));
        widget->setItem(0,2,cell2);
    }

}

