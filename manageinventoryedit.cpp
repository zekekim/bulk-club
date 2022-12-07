#include "manageinventoryedit.h"
#include "ui_manageinventoryedit.h"

ManageInventoryEdit::ManageInventoryEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageInventoryEdit)
{
    ui->setupUi(this);
}

ManageInventoryEdit::~ManageInventoryEdit()
{
    delete ui;
}
