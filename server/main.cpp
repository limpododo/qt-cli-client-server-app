#include <QCoreApplication>

#include "TcpServer.h"
#include "SinGenerator.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    TcpServer server(&app);
    SinGenerator generator;

    server.setDataGenerator(&generator);
    server.start(QHostAddress::LocalHost, 45600);

    return app.exec();
}