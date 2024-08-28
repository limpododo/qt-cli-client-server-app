#include "TcpClient.h"

TcpClient::TcpClient(QObject *parent): QObject(parent), pSocket(new QTcpSocket(this)), pWriter(nullptr) {
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(onDataReceive()));
}

TcpClient::~TcpClient() {
    delete pSocket;
}

void TcpClient::connectToServer(const QHostAddress& ip, const quint16 port) {
    pSocket->connectToHost(ip, port);

    serverIp = ip;
    serverPort = port;
}

void TcpClient::disconnectFromServer() {
    pSocket->disconnectFromHost();
}

void TcpClient::onDataReceive() {
    QByteArray data = pSocket->readAll();

    if(pWriter != nullptr)
        pWriter->write(data.constData(), data.size());
}

void TcpClient::setWriter(IWriter *writer) {
    pWriter = writer;
}



