#include "createpurchase.h"
#include "ui_createpurchase.h"
#include "StoreDashboard.h"

int purchaseNumber;
string purchaseName;
int purchaseQuantity;

CreatePurchase::CreatePurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreatePurchase)
{
    ui->setupUi(this);
}

CreatePurchase::~CreatePurchase()
{
    delete ui;
}

void CreatePurchase::on_lineEdit_editingFinished()
{
    // Membership Number
    purchaseNumber = ui->lineEdit->text().toInt();
}


void CreatePurchase::on_lineEdit_2_editingFinished()
{
    // Item purchaseName
    purchaseName = ui->lineEdit_2->text().toStdString();
}


void CreatePurchase::on_lineEdit_3_editingFinished()
{
    // purchaseQuantity
    purchaseQuantity = ui->lineEdit_3->text().toInt();
}


void CreatePurchase::on_pushButton_clicked()
{
    // Add purchase
    StoreDashboard *store = store->getInstance();
    Item *findItem = store->findItem(purchaseName);
    if (findItem != NULL)
    {
        Sale newSale = Sale(Date{12,12,2022}, purchaseNumber, purchaseName, findItem->price, purchaseQuantity);
        store->addSale(newSale);
    }
}

