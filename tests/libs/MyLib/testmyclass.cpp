#include <QtTest/QtTest>

#include <myclass.h>

class TestMyClass: public QObject
{
    Q_OBJECT

private slots:
    void testDefault();
};

void TestMyClass::testDefault()
{
    MyClass myclass;
}

QTEST_MAIN(TestMyClass)
#include "testmyclass.moc"
