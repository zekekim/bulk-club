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
#include "loginplaceholder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTabWidget *tabWidget = ui->tabWidget;

    SalesReport *salesReport = new SalesReport(this);
    tabWidget->addTab(salesReport, "Sales Report");

    MemberPurchases *memberPurchases = new MemberPurchases(this);
    tabWidget->addTab(memberPurchases, "Member Purchases");

    ItemRevenue *itemRevenue = new ItemRevenue(this);
    tabWidget->addTab(itemRevenue, "Item Revenue");

    ExecutiveRebate *executiveRebate = new ExecutiveRebate(this);
    tabWidget->addTab(executiveRebate, "Executive Rebate");

    ExpiringMemberships *expiringMemberships = new ExpiringMemberships(this);
    tabWidget->addTab(expiringMemberships, "Expiring Memberships");

    tabWidget->setCurrentIndex(0);

    QStackedWidget *stackedWidget = ui->stackedWidget;
    stackedWidget->insertWidget(0, tabWidget);

    ManageMembers *manageMembers = new ManageMembers(this);
    stackedWidget->insertWidget(1, manageMembers);

    CreatePurchase *createPurchase = new CreatePurchase(this);
    stackedWidget->insertWidget(2, createPurchase);

    ManageInventory *manageInventory = new ManageInventory(this);
    stackedWidget->insertWidget(3, manageInventory);

    stackedWidget->setCurrentIndex(0);

    QStackedWidget *stackedWidget2 = ui->stackedWidget_2;
    LoginPlaceholder *login = new LoginPlaceholder(this);
    stackedWidget2->insertWidget(1, login);

    stackedWidget2->setCurrentIndex(1);
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

