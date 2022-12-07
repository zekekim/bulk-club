#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salesreport.h"
#include "memberpurchases.h"
#include "itemrevenue.h"
#include "executiverebate.h"
#include "expiringmemberships.h"
#include "managemembers.h"
#include "createpurchase.h"
#include "manageinventory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTabWidget *tabWidget = ui->tabWidget;

    SalesReport *salesReport = new SalesReport(parent);
    tabWidget->addTab(salesReport, "Sales Report");

    MemberPurchases *memberPurchases = new MemberPurchases(parent);
    tabWidget->addTab(memberPurchases, "Member Purchases");

    ItemRevenue *itemRevenue = new ItemRevenue(parent);
    tabWidget->addTab(itemRevenue, "Item Revenue");

    ExecutiveRebate *executiveRebate = new ExecutiveRebate(parent);
    tabWidget->addTab(executiveRebate, "Executive Rebate");

    ExpiringMemberships *expiringMemberships = new ExpiringMemberships(parent);
    tabWidget->addTab(expiringMemberships, "Expiring Memberships");

    tabWidget->setCurrentIndex(0);

    QStackedWidget *stackedWidget = ui->stackedWidget;
    stackedWidget->insertWidget(0, tabWidget);

    ManageMembers *manageMembers = new ManageMembers(parent);
    stackedWidget->insertWidget(1, manageMembers);

    CreatePurchase *createPurchase = new CreatePurchase(parent);
    stackedWidget->insertWidget(2, createPurchase);

    ManageInventory *manageInventory = new ManageInventory(parent);
    stackedWidget->insertWidget(3, manageInventory);

    stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

