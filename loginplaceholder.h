#ifndef LOGINPLACEHOLDER_H
#define LOGINPLACEHOLDER_H

#include <QWidget>

namespace Ui {
class LoginPlaceholder;
}

class LoginPlaceholder : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPlaceholder(QWidget *parent = nullptr);
    ~LoginPlaceholder();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::LoginPlaceholder *ui;
};

#endif // LOGINPLACEHOLDER_H
