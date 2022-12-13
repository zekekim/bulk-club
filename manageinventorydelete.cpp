#include "manageinventorydelete.h"
#include "ui_manageinventorydelete.h"
#include "StoreDashboard.h"

string itemDelete;

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

void ManageInventoryDelete::on_lineEdit_editingFinished()
{
    // Name Editing
    itemDelete = ui->lineEdit->text().toStdString();
}


void ManageInventoryDelete::on_pushButton_clicked()
{
    StoreDashboard *store = store->getInstance();
    store->deleteItem(false, itemDelete);
    // Clicked
}

