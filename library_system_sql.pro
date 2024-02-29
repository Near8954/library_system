QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookinputform.cpp \
    inputform.cpp \
    main.cpp \
    mainwindow.cpp \
    secondinputform.cpp

HEADERS += \
    bookinputform.h \
    inputform.h \
    mainwindow.h \
    secondinputform.h

FORMS += \
    bookinputform.ui \
    inputform.ui \
    mainwindow.ui \
    secondinputform.ui

TRANSLATIONS += \
    library_system_sql_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
