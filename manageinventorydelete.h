#ifndef MANAGEINVENTORYDELETE_H
#define MANAGEINVENTORYDELETE_H

#include <QWidget>

namespace Ui {
class ManageInventoryDelete;
}

class ManageInventoryDelete : public QWidget
{
    Q_OBJECT

public:
    explicit ManageInventoryDelete(QWidget *parent = nullptr);
    ~ManageInventoryDelete();

private:
    Ui::ManageInventoryDelete *ui;
};

#endif // MANAGEINVENTORYDELETE_H
