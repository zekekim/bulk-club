#ifndef MEMBERPURCHASES_H
#define MEMBERPURCHASES_H

#include <QWidget>

namespace Ui {
class MemberPurchases;
}

class MemberPurchases : public QWidget
{
    Q_OBJECT

public:
    explicit MemberPurchases(QWidget *parent = nullptr);
    ~MemberPurchases();

private:
    Ui::MemberPurchases *ui;
};

#endif // MEMBERPURCHASES_H
