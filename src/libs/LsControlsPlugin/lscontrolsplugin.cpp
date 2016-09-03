#include "lscontrolsplugin.h"
#include <QtQml>

MyPlugin::MyPlugin()
{
}

MyPlugin::~MyPlugin()
{
}

void MyPlugin::registerTypes( const char* a_uri )
{
    Q_UNUSED(a_uri);

    // @uri LsControls
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsButton.ui.qml"),            a_uri,1,0, "LsButton"            );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsCheckBox.ui.qml"),          a_uri,1,0, "LsCheckBox"          );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsComboBox.ui.qml"),          a_uri,1,0, "LsComboBox"          );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsLabel.ui.qml"),             a_uri,1,0, "LsLabel"             );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsProgressBar.ui.qml"),       a_uri,1,0, "LsProgressBar"       );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsRadioButton.ui.qml"),       a_uri,1,0, "LsRadioButton"       );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsSlider.ui.qml"),            a_uri,1,0, "LsSlider"            );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsSwitch.ui.qml"),            a_uri,1,0, "LsSwitch"            );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsText.ui.qml"),              a_uri,1,0, "LsText"              );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsTextField.ui.qml"),         a_uri,1,0, "LsTextField"         );
    qmlRegisterType(QUrl("qrc:/LsControls/Qml/LsApplicationWindow.ui.qml"), a_uri,1,0, "LsApplicationWindow" );
}

void MyPlugin::initializeEngine( QQmlEngine* a_engine, const char* a_uri )
{
    Q_UNUSED(a_engine);
    Q_UNUSED(a_uri);
}



