#include <QtTest/QtTest>

class TestMyApp: public QObject
{
    Q_OBJECT

private slots:
    void testDefault();
};

void TestMyApp::testDefault()
{
}

QTEST_MAIN(TestMyApp)
#include "testmyapp.moc"
