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

private slots:
    void on_item_name_editingFinished();

    void on_item_price_editingFinished();

    void on_add_item_clicked();

private:
    Ui::ManageInventoryAdd *ui;
};

#endif // MANAGEINVENTORYADD_H
