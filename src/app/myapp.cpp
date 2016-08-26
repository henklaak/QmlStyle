#include <QCoreApplication>
#include <QLoggingCategory>
#include <myclass.h>

Q_LOGGING_CATEGORY(LOG_MAIN, "Main", QtDebugMsg)

int main(int argc, char *argv[])
{
    qCDebug(LOG_MAIN) << "Main()";

    QCoreApplication app(argc, argv);

    {
        MyClass myclass;
    }

    qCDebug(LOG_MAIN) << "~Main()";

    return 0;//app.exec();
}
