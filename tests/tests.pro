TEMPLATE = app

include(../defaults.pri)

QT       += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console
CONFIG += c++11
#CONFIG -= app_bundle
#CONFIG -= qt

TARGET = DrawingAppUnitTests

SOURCES += main.cpp

#LIBS += -L../app -lremoteofficedesktop

DESTDIR = $$PWD/../build

