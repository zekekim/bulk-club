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

private:
    Ui::CreatePurchase *ui;
};

#endif // CREATEPURCHASE_H
