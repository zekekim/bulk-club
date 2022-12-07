#include "manageinventoryadd.h"
#include "ui_manageinventoryadd.h"

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
