
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        Soundex.h

SOURCES += \
        SoundexTest.cpp \
        main.cpp
