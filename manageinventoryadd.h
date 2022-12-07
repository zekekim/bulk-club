#ifndef MANAGEINVENTORYADD_H
#define MANAGEINVENTORYADD_H

#include <QWidget>

namespace Ui {
class ManageInventoryAdd;
}

class ManageInventoryAdd : public QWidget
{
    Q_OBJECT

public:
    explicit ManageInventoryAdd(QWidget *parent = nullptr);
    ~ManageInventoryAdd();

private:
    Ui::ManageInventoryAdd *ui;
};

#endif // MANAGEINVENTORYADD_H
