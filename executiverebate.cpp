#include "executiverebate.h"
#include "ui_executiverebate.h"
#include "StoreDashboard.h"

ExecutiveRebate::ExecutiveRebate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExecutiveRebate)
{
    ui->setupUi(this);
    addTable();
}

ExecutiveRebate::~ExecutiveRebate()
{
    delete ui;
}

void ExecutiveRebate::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);
    addTable();
}


void ExecutiveRebate::addTable()
{
    QTableWidget *table = ui->tableWidget;
    StoreDashboard *store = store->getInstance();
    vector<Member> members = *store->members;
    for(auto i = members.begin(); i != members.end();)
    {
        if (i->type == "REGULAR")
        {
            members.erase(i);
        }
        else
        {
            ++i;
        }
    }
    ui->tableWidget->setRowCount(std::size(members));
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Number", "Rebate"});
    for (unsigned int i = 0; i < std::size(members); i++)
    {
        QString name = QString::fromStdString(members.at(i).name);
        QTableWidgetItem *nameCell = new QTableWidgetItem(name);
        table->setItem(i, 0, nameCell);
        QString number = QString::number(members.at(i).number);
        QTableWidgetItem *numberCell = new QTableWidgetItem(number);
        numberCell->setTextAlignment(Qt::AlignRight);
        table->setItem(i, 1, numberCell);
        QString rebate = "$" + QString::number(members.at(i).rebate, 'f', 2);
        QTableWidgetItem *rebateCell = new QTableWidgetItem(rebate);
        rebateCell->setTextAlignment(Qt::AlignRight);
        table->setItem(i, 2, rebateCell);
    }
}
