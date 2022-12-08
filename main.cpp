#include "mainwindow.h"
#include "StoreDashboard.h"

#include <QApplication>
StoreDashboard *StoreDashboard::instance = 0;


int main(int argc, char *argv[])
{
    StoreDashboard *store = store->getInstance();
    store->readDayFile(":/txt/day1.txt");
    store->readDayFile(":/txt/day2.txt");
    store->readDayFile(":/txt/day3.txt");
    store->readDayFile(":/txt/day4.txt");
    store->readDayFile(":/txt/day5.txt");
    store->readDayFile(":/txt/day6.txt");
    store->readDayFile(":/txt/day7.txt");
    store->readMemberFile();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
