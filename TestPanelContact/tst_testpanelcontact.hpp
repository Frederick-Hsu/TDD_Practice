/*!
 *  \file   tst_testpanelcontact.hpp
 *  \brief
 *
 */

#pragma once

#include <QtTest>
#include <QCoreApplication>

#include "../ContactApp/PanelContact.hpp"
#include "../ContactApp/UI_PanelContact.hpp"

class TestPanelContact : public QObject
{
    Q_OBJECT
public:
    TestPanelContact();
    ~TestPanelContact();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void TestConstruction();
    void TestLineEditKeyIn();
    void TestCancelButtonBehaviour();
    void TestConcateButtonBehaviour();
private:
    PanelContact panel;
};
