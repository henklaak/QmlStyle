#pragma once
#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent=nullptr);
    virtual ~MyClass();
};
