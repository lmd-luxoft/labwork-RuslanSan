#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cbattlefield.h"
#include "cplayers.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<CBattleField>("RuslanSan.SeaBattle", 1,0, "BattleField");

    engine.load(url);

    QObject * root = engine.rootObjects().first();
    CPlayers players(root);

    return app.exec();
}
