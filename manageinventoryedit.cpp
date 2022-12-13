#include "manageinventoryedit.h"
#include "ui_manageinventoryedit.h"
#include "StoreDashboard.h"

std::string nameEdit;
double priceEdit;

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

void ManageInventoryEdit::on_lineEdit_2_editingFinished()
{
    // Item Name
    nameEdit = ui->lineEdit_2->text().toStdString();
}


void ManageInventoryEdit::on_lineEdit_editingFinished()
{
    // Item Price
    priceEdit = ui->lineEdit->text().toDouble();
}


void ManageInventoryEdit::on_pushButton_clicked()
{
    StoreDashboard *store = store->getInstance();
    store->findItem(nameEdit)->changePrice(priceEdit);
}

