#-------------------------------------------------
#
# Project created by QtCreator 2024-02-19T08:54:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DZ03
TEMPLATE = app

TEMPLATE    = app
DESTDIR     = bin

OBJECTS_DIR = builddir/obj
MOC_DIR     = builddir/moc
UI_DIR      = builddir/ui
RCC_DIR     = builddir/res

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
        $$PWD/src

SOURCES += \
        $$PWD/src/main.cpp \
        $$PWD/src/mainwindow.cpp \
        $$PWD/src/model.cpp \
        $$PWD/src/arrowdelegate.cpp

HEADERS += \
        $$PWD/src/mainwindow.h \
        $$PWD/src/model.h \
        $$PWD/src/arrowdelegate.h

FORMS += \
        $$PWD/src/mainwindow.ui

RESOURCES += \
       $$PWD/src/resources.qrc
