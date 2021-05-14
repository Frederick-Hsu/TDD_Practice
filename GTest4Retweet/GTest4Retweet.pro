include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ../RetweetApp/RetweetCollection.hpp \
    ../RetweetApp/Tweet.h

SOURCES += \
        ../RetweetApp/RetweetCollection.cpp \
        ../RetweetApp/Tweet.cpp \
        RetweetCollectionTest.cpp \
        main.cpp
