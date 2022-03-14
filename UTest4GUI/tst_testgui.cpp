// #include <QtTest>
#include <QtTest/QtTest>
#include <QCoreApplication>
#include <QtWidgets/QtWidgets>

// add necessary includes here

#define GUI_EVENT_SIMULATING    1
#define GUI_EVENT_REPLAYING     2
#define GUI_EVENT               GUI_EVENT_REPLAYING

class TestGUI : public QObject
{
    Q_OBJECT
public:
    TestGUI();
    ~TestGUI();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testGui();
#if (GUI_EVENT == GUI_EVENT_REPLAYING)
    void testGui_data();
#endif
};

TestGUI::TestGUI()
{

}

TestGUI::~TestGUI()
{

}

void TestGUI::initTestCase()
{

}

void TestGUI::cleanupTestCase()
{

}

#if (GUI_EVENT == GUI_EVENT_SIMULATING)
void TestGUI::testGui()
{
    QLineEdit myLineEdit;

    QTest::keyClicks(&myLineEdit, "hello world");
    QCOMPARE(myLineEdit.text(), QString("hello world"));
}
#elif (GUI_EVENT == GUI_EVENT_REPLAYING)
void TestGUI::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit myLineEdit;
    events.simulate(&myLineEdit);
    QCOMPARE(myLineEdit.text(), expected);
}

void TestGUI::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList enterList;
    enterList.addKeyClick('a');
    QTest::newRow("char") << enterList << "a";

    QTestEventList backspaceList;
    backspaceList.addKeyClick('a');
    backspaceList.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << backspaceList << "";
}
#endif

QTEST_MAIN(TestGUI)

#include "tst_testgui.moc"
