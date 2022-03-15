/*!
 *  \file   tst_testpanelcontact.cpp
 *  \brief
 *
 */

#include "tst_testpanelcontact.hpp"

TestPanelContact::TestPanelContact()
{

}

TestPanelContact::~TestPanelContact()
{

}

void TestPanelContact::initTestCase()
{

}

void TestPanelContact::cleanupTestCase()
{

}

void TestPanelContact::TestConstruction()
{
    QVERIFY2(panel.ui, "ui object had been instantiated.");
    QVERIFY((panel.ui->categoryLineEdit) != nullptr);
}

void TestPanelContact::TestLineEditKeyIn()
{
    QTest::keyClicks(panel.ui->categoryLineEdit, "category");
    QTest::keyClicks(panel.ui->websiteLineEdit, "microport.com");
    QCOMPARE(panel.ui->categoryLineEdit->text(), QString("category"));
    QCOMPARE(panel.ui->websiteLineEdit->text(), QString("microport.com"));
}

void TestPanelContact::TestConcateButtonBehaviour()
{
    QTest::keyClicks(panel.ui->categoryLineEdit, "mbc.");
    QTest::keyClicks(panel.ui->websiteLineEdit, "microport.com");

    QTest::mouseClick(panel.ui->concatButton, Qt::LeftButton);
    qDebug() << panel.ui->displayLabel->text();
    QVERIFY(panel.ui->displayLabel->text() == QString("mbc.microport.com"));
}

void TestPanelContact::TestCancelButtonBehaviour()
{
    QVERIFY(panel.ui->categoryLineEdit->text().isEmpty() == false);
    QVERIFY(panel.ui->websiteLineEdit->text().isEmpty() == false);
    QVERIFY(panel.ui->displayLabel->text().isEmpty() == false);

    QTest::mouseClick(panel.ui->cancelButton, Qt::LeftButton);
    QVERIFY(panel.ui->categoryLineEdit->text().isEmpty() == true);
    QVERIFY(panel.ui->websiteLineEdit->text().isEmpty() == true);
    QVERIFY(panel.ui->displayLabel->text().isEmpty() == true);
}
