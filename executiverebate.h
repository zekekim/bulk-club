#ifndef EXECUTIVEREBATE_H
#define EXECUTIVEREBATE_H

#include <QWidget>

namespace Ui {
class ExecutiveRebate;
}

class ExecutiveRebate : public QWidget
{
    Q_OBJECT

public:
    explicit ExecutiveRebate(QWidget *parent = nullptr);
    ~ExecutiveRebate();

private:
    Ui::ExecutiveRebate *ui;
};

#endif // EXECUTIVEREBATE_H
