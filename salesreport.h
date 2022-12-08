#ifndef SALESREPORT_H
#define SALESREPORT_H
#include "StoreDashboard.h"
#include <QWidget>

namespace Ui {
class SalesReport;
}

class SalesReport : public QWidget
{
    Q_OBJECT

public:
    explicit SalesReport(QWidget *parent = nullptr);
    ~SalesReport();

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::SalesReport *ui;
    void displayTable(vector<Sale> sales, StoreDashboard *store);
};

#endif // SALESREPORT_H
