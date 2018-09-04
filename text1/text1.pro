#-------------------------------------------------
#
# Project created by QtCreator 2018-08-31T13:16:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = text1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    textclass.cpp \
    thread_text.cpp \
    dynamic_curve.cpp

HEADERS  += mainwindow.h \
    textclass.h \
    thread_text.h \
    dynamic_curve.h

FORMS    += mainwindow.ui
CONFIG += qwt
DEFINES += QT_DLL QWT_DLL
LIBS += -L"G:\lean\qwt-6.1.3\build-qwt-Desktop_Qt_5_8_0_MinGW_32bit-Debug\lib" -lqwtd
LIBS += -L"G:\lean\qwt-6.1.3\build-qwt-Desktop_Qt_5_8_0_MinGW_32bit-Debug\lib" -lqwt
INCLUDEPATH += F:\Qt\Qt5.8.0\5.8\mingw53_32\include\QWT

