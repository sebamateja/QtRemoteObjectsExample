#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "rep_Controller_replica.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<ControllerReplica>("org.controller", 1, 0, "Controller",
        [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
            static ControllerReplica* rep = new ControllerReplica();
            QUrl url("tcp://192.168.1.105:65212");
            static QRemoteObjectNode* node = new QRemoteObjectNode(url, rep);
            if (!rep->node()) {
                rep->setNode(node);
            }
            return rep;
        });

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
