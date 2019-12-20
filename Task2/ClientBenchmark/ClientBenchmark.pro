QT += core network
QT -= gui

CONFIG += c++11

TARGET = ClientBenchmark
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    clientbenchmarkthread.cpp \
    benchmarkcalculator.cpp

HEADERS += \
    clientbenchmarkthread.h \
    benchmarkcalculator.h
