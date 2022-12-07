#ifndef MANAGEINVENTORY_H
#define MANAGEINVENTORY_H

#include <QWidget>

namespace Ui {
class ManageInventory;
}

class ManageInventory : public QWidget
{
    Q_OBJECT

public:
    explicit ManageInventory(QWidget *parent = nullptr);
    ~ManageInventory();

private:
    Ui::ManageInventory *ui;
};

#endif // MANAGEINVENTORY_H
