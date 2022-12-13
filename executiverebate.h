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
    void showEvent(QShowEvent* event);
    Ui::ExecutiveRebate *ui;
    void addTable();
};

#endif // EXECUTIVEREBATE_H
