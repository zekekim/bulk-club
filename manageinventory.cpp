#include "manageinventory.h"
#include "ui_manageinventory.h"
#include "manageinventoryadd.h"
#include "manageinventorydelete.h"
#include "manageinventoryedit.h"

ManageInventory::ManageInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageInventory)
{
    ui->setupUi(this);

    QTabWidget *tabWidget = ui->tabWidget;

    ManageInventoryAdd *manageInventoryAdd = new ManageInventoryAdd(parent);
    tabWidget->addTab(manageInventoryAdd, "Add");

    ManageInventoryDelete *manageInventoryDelete = new ManageInventoryDelete(parent);
    tabWidget->addTab(manageInventoryDelete, "Delete");

    ManageInventoryEdit *manageInventoryEdit = new ManageInventoryEdit(parent);
    tabWidget->addTab(manageInventoryEdit, "Edit");

    tabWidget->setCurrentIndex(0);
}

ManageInventory::~ManageInventory()
{
    delete ui;
}
