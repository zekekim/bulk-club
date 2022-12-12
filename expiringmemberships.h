#ifndef EXPIRINGMEMBERSHIPS_H
#define EXPIRINGMEMBERSHIPS_H

#include <QWidget>
#include "StoreDashboard.h"

namespace Ui {
class ExpiringMemberships;
}

class ExpiringMemberships : public QWidget
{
    Q_OBJECT

public:
    explicit ExpiringMemberships(QWidget *parent = nullptr);
    ~ExpiringMemberships();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::ExpiringMemberships *ui;
    void setTable(vector<Member> members);
};

#endif // EXPIRINGMEMBERSHIPS_H
