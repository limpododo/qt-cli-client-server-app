#include <QCoreApplication>
#include "TcpClient.h"

#define PATH_TO_FILE "/home/tmp/file"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    BinFileWriter writer(PATH_TO_FILE);
    TcpClient client(&app);

    client.setWriter(&writer);
    client.connectToServer(QHostAddress::LocalHost, 45600);

    return app.exec();
}