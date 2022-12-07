#include "itemrevenue.h"
#include "ui_itemrevenue.h"

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
