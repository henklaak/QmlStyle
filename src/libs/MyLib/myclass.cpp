#include "myclass.h"
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(LOG_MYCLASS, "MyClass", QtDebugMsg)

MyClass::MyClass(QObject *parent)
    : QObject(parent)
{
    qCDebug(LOG_MYCLASS) << "MyClass()";
}

MyClass::~MyClass()
{
    qCDebug(LOG_MYCLASS) << "~MyClass()";
}
