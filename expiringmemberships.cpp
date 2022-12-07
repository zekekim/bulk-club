#include "expiringmemberships.h"
#include "ui_expiringmemberships.h"

ExpiringMemberships::ExpiringMemberships(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpiringMemberships)
{
    ui->setupUi(this);
}

ExpiringMemberships::~ExpiringMemberships()
{
    delete ui;
}
