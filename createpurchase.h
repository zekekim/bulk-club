#ifndef CREATEPURCHASE_H
#define CREATEPURCHASE_H

#include <QWidget>

namespace Ui {
class CreatePurchase;
}

class CreatePurchase : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePurchase(QWidget *parent = nullptr);
    ~CreatePurchase();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::CreatePurchase *ui;
};

#endif // CREATEPURCHASE_H
