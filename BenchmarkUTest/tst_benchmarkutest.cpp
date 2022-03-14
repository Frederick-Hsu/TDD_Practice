#include <QtTest>
#include <QCoreApplication>

#include <QString>

// add necessary includes here

class BenchmarkUTest : public QObject
{
    Q_OBJECT
public:
    BenchmarkUTest();
    ~BenchmarkUTest();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void simpleBenchmark();
private slots:
    void multiple();
    void multiple_data();
};

BenchmarkUTest::BenchmarkUTest()
{

}

BenchmarkUTest::~BenchmarkUTest()
{

}

void BenchmarkUTest::initTestCase()
{

}

void BenchmarkUTest::cleanupTestCase()
{

}

void BenchmarkUTest::simpleBenchmark()
{
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    QCOMPARE(str1.localeAwareCompare(str2), 0);
    QBENCHMARK {
        str1.localeAwareCompare(str2);
    }
}

void BenchmarkUTest::multiple()
{
    QFETCH(bool, useLocaleCompare);
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    int result;
    if (useLocaleCompare)
    {
        QBENCHMARK {
            result = str1.localeAwareCompare(str2);
        }
    }
    else
    {
        QBENCHMARK {
            result = (str1 == str2);
        }
    }
    Q_UNUSED(result);
}

void BenchmarkUTest::multiple_data()
{
    QTest::addColumn<bool>("useLocaleCompare");
    QTest::newRow("locale aware compare") << true;
    QTest::newRow("standard compare") << false;
}

QTEST_MAIN(BenchmarkUTest)

#include "tst_benchmarkutest.moc"
