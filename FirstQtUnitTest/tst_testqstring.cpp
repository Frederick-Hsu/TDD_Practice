#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TestQString : public QObject
{
    Q_OBJECT
public:
    TestQString();
    ~TestQString();
private slots:
    void initTestCase();
    void cleanupTestCase();
private slots:
    /* User's test cases list here */
    void toUpper();
    void toUpper_data();
};

TestQString::TestQString()
{

}

TestQString::~TestQString()
{

}

void TestQString::initTestCase()
{
    qDebug("Called before everything else.");
}

void TestQString::cleanupTestCase()
{
    qDebug("Called after all test cases executed.");
}

void TestQString::toUpper()
{
#if 0
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
    QCOMPARE(str.toUpper(), QString("HELLO"));;
#else
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
#endif
}

/*!
 *  \brief  Writting the Data Function
 *  \details    A test function's associated data function carries the same name, appended by _data.
 */
void TestQString::toUpper_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower")  << "hello" << "HELLO";
    QTest::newRow("mixed")      << "Hello" << "HELLO";
    QTest::newRow("all upper")  << "HELLO" << "HELLO";
}

QTEST_MAIN(TestQString)

#include "tst_testqstring.moc"
