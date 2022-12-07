#include "manageinventorydelete.h"
#include "ui_manageinventorydelete.h"

ManageInventoryDelete::ManageInventoryDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageInventoryDelete)
{
    ui->setupUi(this);
}

ManageInventoryDelete::~ManageInventoryDelete()
{
    delete ui;
}
