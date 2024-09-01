#include "TcpServer.h"

TcpServer::TcpServer(QObject* parent): QObject(parent), pServer(new QTcpServer(this)), pDataGenerator(nullptr),
pBroadcastTimer(new QTimer(this)) {
    pServer->setMaxPendingConnections(MAX_CLIENTS_COUNT);

    connect(pBroadcastTimer, SIGNAL(timeout()), this, SLOT(onSendData()));
    connect(pServer, SIGNAL(newConnection()), this, SLOT(onNewClient()));
}

TcpServer::~TcpServer() {
    this->stop();
    pServer->deleteLater();
}

void TcpServer::start(const QHostAddress& serverIp, quint16 serverPort) {
    qDebug() << "Start listening on:" << serverIp.toString() << ":" << serverPort;
    pServer->listen(serverIp, serverPort);
}

void TcpServer::stop() {
    for(auto client : clients) {
        client->close();
        client->deleteLater();
        clients.remove(client);
    }
    pServer->close();
}

void TcpServer::onNewClient() {
    auto clientSocket = pServer->nextPendingConnection();
    connect(clientSocket,SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));

    clients.insert(clientSocket);

    qDebug() << "New Client:" << clientSocket->peerAddress() << clientSocket->peerPort();
    controlBroadcastTimer();
}

void TcpServer::onClientDisconnected() {
    auto clientSocket = qobject_cast<QTcpSocket*>(sender());
    clients.remove(clientSocket);

    qDebug() << "Client" << clientSocket->peerAddress().toString() << clientSocket->peerPort() << "is disconnected.";

    clientSocket->deleteLater();
    controlBroadcastTimer();
}

void TcpServer::sendData(const char* pData, quint32 size) {
    for(auto client : clients) {
        client->write(pData, size);
    }
}

void TcpServer::onSendData() {
    if(pDataGenerator != nullptr) {
        QByteArray data;

        data = pDataGenerator->getData();
        sendData(data, data.size());
    }
}

void TcpServer::controlBroadcastTimer() {
    if(clients.empty()) {
        qDebug() << "Broadcast has stopped.";
        pBroadcastTimer->stop();
    } else if (clients.size() == 1 && !pBroadcastTimer->isActive()) {
        qDebug() << "Broadcast has started.";
        pBroadcastTimer->start(BROADCAST_TIMEOUT_MS);
    }
}






