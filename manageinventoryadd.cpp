#include "manageinventoryadd.h"
#include "ui_manageinventoryadd.h"
#include "StoreDashboard.h"


std::string itemNameAdd;
double itemPriceAdd;


ManageInventoryAdd::ManageInventoryAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageInventoryAdd)
{
    ui->setupUi(this);
}

ManageInventoryAdd::~ManageInventoryAdd()
{
    delete ui;
}

void ManageInventoryAdd::on_item_name_editingFinished()
{
    itemNameAdd = ui->item_name->text().toStdString();
}


void ManageInventoryAdd::on_item_price_editingFinished()
{
    itemPriceAdd = ui->item_price->text().toDouble();
}


void ManageInventoryAdd::on_add_item_clicked()
{
    StoreDashboard *store = store->getInstance();
    store->addItem(true, Item(itemNameAdd, 0, 0, itemPriceAdd));
}

