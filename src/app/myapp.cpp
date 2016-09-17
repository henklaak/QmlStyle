#include <QGuiApplication>
#include <QLoggingCategory>
#include <QQmlApplicationEngine>
#include <QImage>
#include <QPainter>
#include <QPen>

int main( int argc, char *argv[] )
{
    QGuiApplication app( argc, argv );
    QQmlApplicationEngine engine( qApp );

    qputenv("QT_QUICK_CONTROLS_1_STYLE", "Flat");

    engine.addImportPath( "." );
    engine.load( QUrl( QStringLiteral( "qrc:/Qml/MyApp.qml" ) ) );

    return app.exec();
}
