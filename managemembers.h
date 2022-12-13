#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <QWidget>

namespace Ui {
class ManageMembers;
}

class ManageMembers : public QWidget
{
    Q_OBJECT

public:
    explicit ManageMembers(QWidget *parent = nullptr);
    ~ManageMembers();

private slots:
    void on_member_name_editingFinished();

    void on_member_number_editingFinished();

    void on_type_currentIndexChanged(int index);

    void on_add_member_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ManageMembers *ui;
};

#endif // MANAGEMEMBERS_H
