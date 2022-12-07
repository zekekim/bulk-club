#ifndef EXPIRINGMEMBERSHIPS_H
#define EXPIRINGMEMBERSHIPS_H

#include <QWidget>

namespace Ui {
class ExpiringMemberships;
}

class ExpiringMemberships : public QWidget
{
    Q_OBJECT

public:
    explicit ExpiringMemberships(QWidget *parent = nullptr);
    ~ExpiringMemberships();

private:
    Ui::ExpiringMemberships *ui;
};

#endif // EXPIRINGMEMBERSHIPS_H
