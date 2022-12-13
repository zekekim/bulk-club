#ifndef MEMBERPURCHASES_H
#define MEMBERPURCHASES_H

#include <QWidget>
#include "StoreDashboard.h"

namespace Ui {
class MemberPurchases;
}

class MemberPurchases : public QWidget
{
    Q_OBJECT

public:
    explicit MemberPurchases(QWidget *parent = nullptr);
    ~MemberPurchases();

private slots:
    void on_comboBox_currentIndexChanged(int index);


    void on_lineEdit_editingFinished();

private:
    void showEvent(QShowEvent* event);
    Ui::MemberPurchases *ui;
    void displayTable(vector<Member> members, StoreDashboard *store);
};

#endif // MEMBERPURCHASES_H
