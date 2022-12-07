#include "createpurchase.h"
#include "ui_createpurchase.h"

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
