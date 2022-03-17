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

void TestPanelContact::TestFocus()
{
    /* clean up all the text message firstly */
    QTest::mouseClick(panel.ui->cancelButton, Qt::LeftButton);

    /* enables focus and widget events */
    QApplication::setActiveWindow(&panel);
    /* set initial focus */
    panel.ui->categoryLineEdit->setFocus();
    QVERIFY2(panel.ui->categoryLineEdit->hasFocus(), "category QLineEdit widget doesn't have focus");

    /* Write the focused widget: categoryLineEdit */
    QTest::keyClicks(QApplication::focusWidget(), "medbot.");
    /* move focus to next widget */
    QTest::keyClick(&panel, Qt::Key_Tab);
    QVERIFY2(panel.ui->websiteLineEdit->hasFocus(), "website QLineEdit widget doesn't have focus");
    /* write the focused widget: websiteLineEdit */
    QTest::keyClicks(QApplication::focusWidget(), "microport.com");

    QTest::keyClick(&panel, Qt::Key_Tab);   /* move focus to next widget */
    QVERIFY2(panel.ui->concatButton->hasFocus(), "concate button has not yet owned the focus.");
    /* press concateButton by using space key */
    QTest::keyClick(QApplication::focusWidget(), Qt::Key_Space);
    QCOMPARE(panel.ui->displayLabel->text(), QString("medbot.microport.com"));

    QTest::keyClick(&panel, Qt::Key_Tab);
    QVERIFY2(panel.ui->cancelButton->hasFocus(), "cancelButton has not yet owned the focus");
    QTest::keyClick(QApplication::focusWidget(), Qt::Key_Space);
    QVERIFY2(panel.ui->categoryLineEdit->text().isEmpty(), "Cancel button didn't work on categoryLineEdit widget.");
    QVERIFY2(panel.ui->websiteLineEdit->text().isEmpty(), "Cancel button didn't work on websiteLineEdit widget.");
    QVERIFY2(panel.ui->displayLabel->text().isEmpty(), "Cancel button didn't work on displayLabel widget.");
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

    auto args = spyToConcateButton.takeFirst();
    QCOMPARE(args.at(0).toString(), panel.ui->categoryLineEdit->text() + panel.ui->websiteLineEdit->text());

    /* Click the cancelButton */
    QTest::mouseClick(panel.ui->cancelButton, Qt::LeftButton);
    QCOMPARE(spyToConcateButton.count(), 0);
    QCOMPARE(spyToCancelButton.count(), 1);
    args = spyToCancelButton.takeFirst();
    QVERIFY2(args.empty(), "DataCleared signal has parameters now?");
}

void TestPanelContact::TestConcatenate()
{
    /* Retrieve the data or a row using the macro */
    QFETCH(QTestEventList, category);
    QFETCH(QTestEventList, website);
    QFETCH(QString, display_value);

    /* Simulate the events from event list one-by-one on the destination widget */
    QTest::mouseClick(panel.ui->cancelButton, Qt::LeftButton);
    category.simulate(panel.ui->categoryLineEdit);
    website.simulate(panel.ui->websiteLineEdit);
    /* Click the button Concatenate */
    QTest::mouseClick(panel.ui->concatButton, Qt::LeftButton);
    /* Compare the actual result with expected one */
    QCOMPARE(panel.ui->displayLabel->text(), display_value);
}

void TestPanelContact::TestConcatenate_data()
{
    QTest::addColumn<QTestEventList>("category");;
    QTest::addColumn<QTestEventList>("website");
    QTest::addColumn<QString>("display_value");

    QTestEventList enterCategoryList;
    QTestEventList enterWebsiteList;
    enterCategoryList.addKeyClicks("mbc.");
    enterCategoryList.addKeyClicks("microport.com");
    QTest::newRow("Normal A + B") << enterCategoryList << enterWebsiteList << QString("mbc.microport.com");

    /* Empty category + Normal website */
    enterCategoryList.addKeyClicks("");
    enterWebsiteList.addKeyClicks("medbot.microport.com");
    QTest::newRow("Empty category + Normal website") << enterCategoryList << enterWebsiteList << QString("medbot.microport.com");
}
