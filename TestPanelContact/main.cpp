/*!
 *  \file   main.cpp
 *  \brief  Implement the main() portal function.
 *
 */

#include "tst_testpanelcontact.hpp"

#define stringify(name) #name

class Dummy : public QObject
{
    Q_OBJECT
public:
    Dummy() {}
    ~Dummy() {}
};

#if true
    QTEST_MAIN(TestPanelContact)
#else
    int main(int argc, char* argv[])
    {
        QtCoverageScanner _qtCoverageScanner(stringify(TestPanelContact));
        ::QTest::Internal::callInitMain<TestPanelContact>();

        QGuiApplication app(argc, argv);
        app.setAttribute(Qt::AA_Use96Dpi, true);

        TestPanelContact tc;
        QTest::setMainSourcePath(__FILE__, QT_TESTCASE_BUILDDIR);
        return QTest::qExec(&tc, argc, argv);
    }
#endif

#include "main.moc"

