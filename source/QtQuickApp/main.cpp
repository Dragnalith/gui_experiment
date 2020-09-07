#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QCoreApplication::addLibraryPath("E:/Qt/5.15.0/msvc2019_64/plugins");

    QQmlApplicationEngine engine;
    engine.addImportPath("E:/Qt/5.15.0/msvc2019_64/qml");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	    
    return app.exec();
}