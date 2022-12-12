#include "loginplaceholder.h"
#include "ui_loginplaceholder.h"

#include <QStackedWidget>

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
    // <--- Do some login check here
    // Redirect to main dashboard window
    ((QStackedWidget*)(this->parentWidget()))->setCurrentIndex(0);
}

