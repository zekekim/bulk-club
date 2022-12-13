#ifndef MANAGEINVENTORYEDIT_H
#define MANAGEINVENTORYEDIT_H

#include <QWidget>

namespace Ui {
class ManageInventoryEdit;
}

class ManageInventoryEdit : public QWidget
{
    Q_OBJECT

public:
    explicit ManageInventoryEdit(QWidget *parent = nullptr);
    ~ManageInventoryEdit();

private slots:
    void on_lineEdit_2_editingFinished();

    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::ManageInventoryEdit *ui;
};

#endif // MANAGEINVENTORYEDIT_H
