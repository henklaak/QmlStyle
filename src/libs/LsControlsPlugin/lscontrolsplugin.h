#pragma once

#include <QQmlExtensionPlugin>

class MyPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA( IID "org.qt-project.Qt.QQmlExtensionInterface" )

public:
    MyPlugin();
    virtual ~MyPlugin();

    void registerTypes( const char* a_uri );
    void initializeEngine( QQmlEngine* a_engine, const char* a_uri ) Q_DECL_OVERRIDE;
};
