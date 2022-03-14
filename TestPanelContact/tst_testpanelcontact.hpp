/*!
 *  \file   tst_testpanelcontact.hpp
 *  \brief
 *
 */

#pragma once

#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TestPanelContact : public QObject
{
    Q_OBJECT
public:
    TestPanelContact();
    ~TestPanelContact();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};
