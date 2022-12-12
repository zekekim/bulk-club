#include "expiringmemberships.h"
#include "ui_expiringmemberships.h"
#include "StoreDashboard.h"

ExpiringMemberships::ExpiringMemberships(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpiringMemberships)
{
    ui->setupUi(this);
    StoreDashboard *store = store->getInstance();
    vector<Member> members = *store->members;
    for (auto i = members.begin(); i != members.end();)
    {
        if (i->expiration.month == 1)
        {
            ++i;
        }
        else
        {
            members.erase(i);
        }
    }
    setTable(members);
}

void ExpiringMemberships::setTable(vector<Member> members)
{
    QTableWidget *table = ui->tableWidget;
    ui->tableWidget->setRowCount(std::size(members));
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Member Name", "Annual Due", "Member Expiration"});
    for (unsigned int i = 0; i < std::size(members); i++)
    {
        QString name = QString::fromStdString(members.at(i).name);
        QTableWidgetItem *nameCell = new QTableWidgetItem(name);
        table->setItem(i, 0, nameCell);
        double resubPrice;
        if (members.at(i).type == "Executive")
        {
            resubPrice = 120.00;
        }
        else
        {
            resubPrice = 65.00;
        }
        QString number = "$" + QString::number(resubPrice, 'f', 2);
        QTableWidgetItem *numberCell = new QTableWidgetItem(number);
        numberCell->setTextAlignment(Qt::AlignRight);
        table->setItem(i, 1, numberCell);
        QString month = QString::number(members.at(i).expiration.month);
        QString day = QString::number(members.at(i).expiration.date);
        QString year = QString::number(members.at(i).expiration.year);
        QString fullDate = month + "/" + day + "/" + year;
        QTableWidgetItem *rebateCell = new QTableWidgetItem(fullDate);
        rebateCell->setTextAlignment(Qt::AlignRight);
        table->setItem(i, 2, rebateCell);
    }
}

ExpiringMemberships::~ExpiringMemberships()
{
    delete ui;
}

void ExpiringMemberships::on_comboBox_currentIndexChanged(int index)
{
    StoreDashboard *store = store->getInstance();
    vector<Member> members = *store->members;
    for (auto i = members.begin(); i != members.end();)
    {
        if (i->expiration.month == index + 1)
        {
            ++i;
        }
        else
        {
            members.erase(i);
        }
    }
    setTable(members);
}

