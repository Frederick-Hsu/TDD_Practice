include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        Soundex.h \
        tst_gmocktestcase.h

SOURCES += \
        SoundexTest.cpp \
        main.cpp
