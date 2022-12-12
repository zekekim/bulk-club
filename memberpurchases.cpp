#include "memberpurchases.h"
#include "ui_memberpurchases.h"

MemberPurchases::MemberPurchases(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberPurchases)
{
    ui->setupUi(this);
    StoreDashboard *store = store->getInstance();
    vector<Member> *members = store->members;
    displayTable(*members, store);
}

MemberPurchases::~MemberPurchases()
{
    delete ui;
}

void MemberPurchases::displayTable(vector<Member> members, StoreDashboard *store)
{
    QTableWidget *table = ui->tableWidget;
    table->setRowCount(std::size(members));
    table->setColumnCount(6);
    table->setColumnWidth(2, 200);
    table->setHorizontalHeaderLabels({"Name", "Number", "Type", "Expiration", "Rebate", "Total"});
    qDebug() << std::size(members);
    for (unsigned int i = 0; i < std::size(members); i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j==0)
            {
                QString member = QString::fromStdString(members.at(i).name);
                QTableWidgetItem *item = new QTableWidgetItem(member);
                table->setItem(i,j,item);

            }
            if (j==1)
            {
                QString number = QString::fromStdString(std::to_string(members.at(i).number));
                QTableWidgetItem *item = new QTableWidgetItem(number);
                item->setTextAlignment(Qt::AlignRight);
                table->setItem(i,j,item);

            }
            if (j==2)
            {
                QString type = QString::fromStdString(members.at(i).type);
                QTableWidgetItem *item = new QTableWidgetItem(type);
                table->setItem(i,j,item);
            }
            if (j==3)
            {
                QString date = QString::fromStdString(std::to_string(members.at(i).expiration.month) + "/" + std::to_string(members.at(i).expiration.date) + "/" + std::to_string(members.at(i).expiration.year));
                QTableWidgetItem *item = new QTableWidgetItem(date);
                table->setItem(i, j, item);
            }
            if (j==4)
            {
                QString rebate = QString::fromStdString(std::to_string(members.at(i).rebate)).replace("0000","").insert(0,"$");
                QTableWidgetItem *item = new QTableWidgetItem(rebate);
                item->setTextAlignment(Qt::AlignRight);
                table->setItem(i,j,item);
            }
            if (j==5)
            {

                QString total = QString::fromStdString(std::to_string(members.at(i).total)).replace("0000","").insert(0,"$");
                QTableWidgetItem *item = new QTableWidgetItem(total);
                item->setTextAlignment(Qt::AlignRight);
                table->setItem(i,j,item);
            }
        }
    }
    double totalSpent = store->getMembersTotal(members);
    ui->label_2->setText("$" + QString::number(totalSpent, 'f', 2));
}
int searchType = 0;

void MemberPurchases::on_comboBox_currentIndexChanged(int index)
{
    searchType = index;
}




void MemberPurchases::on_lineEdit_editingFinished()
{
    StoreDashboard *store = store->getInstance();
    vector<Member> members = *store->members;
    if (searchType == 0 && ui->lineEdit->text().toStdString() != "")
    {
        for (auto i = members.begin(); i != members.end();)
        {
            if (i->isName(ui->lineEdit->text().toStdString()))
            {
                ++i;
            }
            else
            {
                members.erase(i);
            }
        }
        qDebug() << "HERE";
        displayTable(members, store);
    }
    else if (searchType == 1 && ui->lineEdit->text().toStdString() != "")
    {

        for (auto i = members.begin(); i != members.end();)
        {
            if (i->isNumber(stoi(ui->lineEdit->text().toStdString())))
            {
                ++i;
            }
            else
            {
                members.erase(i);
            }
        }
        qDebug() << "HERE";
        displayTable(members, store);
    }
    else if (ui->lineEdit->text() == "")
    {
        displayTable(members, store);
    }
}

