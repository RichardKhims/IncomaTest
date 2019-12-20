QT += core network
QT -= gui

CONFIG += c++11

TARGET = server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tcpserver.cpp \
    clienthandlertthread.cpp \
    datamodel.cpp

HEADERS += \
    tcpserver.h \
    clienthandlertthread.h \
    datamodel.h \
    signletondestroyer.h
