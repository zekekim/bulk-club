QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createpurchase.cpp \
    executiverebate.cpp \
    expiringmemberships.cpp \
    itemrevenue.cpp \
    main.cpp \
    mainwindow.cpp \
    manageinventory.cpp \
    manageinventoryadd.cpp \
    manageinventorydelete.cpp \
    manageinventoryedit.cpp \
    managemembers.cpp \
    memberpurchases.cpp \
    salesreport.cpp

HEADERS += \
    createpurchase.h \
    executiverebate.h \
    expiringmemberships.h \
    itemrevenue.h \
    mainwindow.h \
    manageinventory.h \
    manageinventoryadd.h \
    manageinventorydelete.h \
    manageinventoryedit.h \
    managemembers.h \
    memberpurchases.h \
    salesreport.h

FORMS += \
    createpurchase.ui \
    executiverebate.ui \
    expiringmemberships.ui \
    itemrevenue.ui \
    mainwindow.ui \
    manageinventory.ui \
    manageinventoryadd.ui \
    manageinventorydelete.ui \
    manageinventoryedit.ui \
    managemembers.ui \
    memberpurchases.ui \
    salesreport.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
