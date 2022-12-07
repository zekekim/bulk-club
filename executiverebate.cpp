#include "executiverebate.h"
#include "ui_executiverebate.h"

ExecutiveRebate::ExecutiveRebate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExecutiveRebate)
{
    ui->setupUi(this);
}

ExecutiveRebate::~ExecutiveRebate()
{
    delete ui;
}
