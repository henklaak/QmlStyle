#pragma once

#include <QQmlExtensionPlugin>

class LsControlsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA( IID "org.qt-project.Qt.QQmlExtensionInterface" )

public:
    explicit LsControlsPlugin( QObject *parent = nullptr );
    virtual ~LsControlsPlugin();

    void registerTypes( const char* a_uri );
    void initializeEngine( QQmlEngine* a_engine, const char* a_uri ) Q_DECL_OVERRIDE;
};
