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
                              a_uri, 2, 5, "LsColors" );

    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsButton.qml" ),
                     a_uri, 2, 5, "LsButton" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsCheckBox.qml" ),
                     a_uri, 2, 5, "LsCheckBox" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsComboBox.qml" ),
                     a_uri, 2, 5, "LsComboBox" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsLabel.qml" ),
                     a_uri, 2, 5, "LsLabel" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsProgressBar.qml" ),
                     a_uri, 2, 5, "LsProgressBar" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsRadioButton.qml" ),
                     a_uri, 2, 5, "LsRadioButton" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsSlider.qml" ),
                     a_uri, 2, 5, "LsSlider" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsSwitch.qml" ),
                     a_uri, 2, 5, "LsSwitch" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsText.qml" ),
                     a_uri, 2, 5, "LsText" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsTextField.qml" ),
                     a_uri, 2, 5, "LsTextField" );
    qmlRegisterType( QUrl( "qrc:/LsControls/Qml/LsApplicationWindow.qml" ),
                     a_uri, 2, 5, "LsApplicationWindow" );
}

void LsControlsPlugin::initializeEngine( QQmlEngine* a_engine, const char* a_uri )
{
    Q_UNUSED( a_engine );
    Q_UNUSED( a_uri );
}
