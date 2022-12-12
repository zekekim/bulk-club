#ifndef ITEMREVENUE_H
#define ITEMREVENUE_H

#include <QWidget>

namespace Ui {
class ItemRevenue;
}

class ItemRevenue : public QWidget
{
    Q_OBJECT

public:
    explicit ItemRevenue(QWidget *parent = nullptr);
    ~ItemRevenue();

private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::ItemRevenue *ui;
};

#endif // ITEMREVENUE_H
