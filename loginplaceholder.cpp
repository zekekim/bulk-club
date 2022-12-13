#include "loginplaceholder.h"
#include "ui_loginplaceholder.h"
#include "StoreDashboard.h"

#include <QStackedWidget>

int loginIndex = 0;

LoginPlaceholder::LoginPlaceholder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPlaceholder)
{
    ui->setupUi(this);
}

LoginPlaceholder::~LoginPlaceholder()
{
    delete ui;
}

void LoginPlaceholder::on_pushButton_clicked()
{
    ((QStackedWidget*)(this->parentWidget()))->setCurrentIndex(0);
}


void LoginPlaceholder::on_comboBox_currentIndexChanged(int index)
{
    loginIndex = index;
    StoreDashboard *store = store->getInstance();
    store->setAdmin(loginIndex);
}

