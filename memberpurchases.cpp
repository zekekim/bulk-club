#include "memberpurchases.h"
#include "ui_memberpurchases.h"

MemberPurchases::MemberPurchases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberPurchases)
{
    ui->setupUi(this);
}

MemberPurchases::~MemberPurchases()
{
    delete ui;
}
