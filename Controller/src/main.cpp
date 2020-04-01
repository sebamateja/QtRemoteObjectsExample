#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QTcpServer>
#include <QHostAddress>
#include <QObject>

#include "Controller.h"
#include "rep_Controller_source.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication app(argc,argv);

    Controller srcController;

    QRemoteObjectHost srcNode;
    auto addressUrl = QUrl(QString("tcp://192.168.1.105:65212"));
    srcNode.setHostUrl(addressUrl);

    srcNode.enableRemoting(&srcController);

    return app.exec();
}
