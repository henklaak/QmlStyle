#include "lscontrolsplugin.h"
#include <QtQml>

Q_LOGGING_CATEGORY( LOG_LSCONTROLSPLUGIN, "LsControlsPlugin", QtDebugMsg )

LsControlsPlugin::LsControlsPlugin( QObject *a_parent )
    : QQmlExtensionPlugin( a_parent )
{
    qCDebug( LOG_LSCONTROLSPLUGIN ) << "LsControlsPlugin()";
}

LsControlsPlugin::~LsControlsPlugin()
{
    qCDebug( LOG_LSCONTROLSPLUGIN ) << "~LsControlsPlugin()";
}

void LsControlsPlugin::registerTypes( const char* a_uri )
{
    qCDebug( LOG_LSCONTROLSPLUGIN ) << "registerTypes()" << a_uri;

    qmlRegisterSingletonType( QUrl( "qrc:/LsControls/Qml/LsColors.qml" ),
                              a_uri, 1, 0, "LsColors" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsButton.qml" ),
                     a_uri, 1, 0, "LsButton" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsCheckBox.qml" ),
                     a_uri, 1, 0, "LsCheckBox" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsComboBox.qml" ),
                     a_uri, 1, 0, "LsComboBox" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsLabel.qml" ),
                     a_uri, 1, 0, "LsLabel" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsProgressBar.qml" ),
                     a_uri, 1, 0, "LsProgressBar" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsRadioButton.qml" ),
                     a_uri, 1, 0, "LsRadioButton" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsSlider.qml" ),
                     a_uri, 1, 0, "LsSlider" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsSwitch.qml" ),
                     a_uri, 1, 0, "LsSwitch" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsText.qml" ),
                     a_uri, 1, 0, "LsText" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsTextField.qml" ),
                     a_uri, 1, 0, "LsTextField" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsApplicationWindow.qml" ),
                     a_uri, 1, 0, "LsApplicationWindow" );
}

void LsControlsPlugin::initializeEngine( QQmlEngine* a_engine, const char* a_uri )
{
    Q_UNUSED( a_engine );
    Q_UNUSED( a_uri );
}
