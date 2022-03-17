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
void TestPanelContact::TestSignals()
{
    /* set inputs */
    panel.ui->categoryLineEdit->setText(QString("medbot."));
    panel.ui->websiteLineEdit->setText(QString("microport.com"));

    /* create QSignalSpy objects */
    QSignalSpy spyToConcateButton(&panel, &PanelContact::DataAvailable);
    QSignalSpy spyToCancelButton(&panel, &PanelContact::DataCleared);

    /* Click the concatButton */
    QTest::mouseClick(panel.ui->concatButton, Qt::LeftButton);
    QCOMPARE(spyToConcateButton.count(), 1);
    QCOMPARE(spyToCancelButton.count(), 0);

    QList args = spyToConcateButton.takeFirst();
    QCOMPARE(args.at(0).toString(), panel.ui->categoryLineEdit->text() + panel.ui->websiteLineEdit->text());

    /* Click the cancelButton */
    QTest::mouseClick(panel.ui->cancelButton, Qt::LeftButton);
    QCOMPARE(spyToConcateButton.count(), 0);
    QCOMPARE(spyToCancelButton.count(), 1);
    args = spyToCancelButton.takeFirst();
    QVERIFY2(args.empty(), "DataCleared signal has parameters now?");
}
