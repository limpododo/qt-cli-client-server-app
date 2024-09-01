#ifndef INOBITEC_TEST_TASK_TCPSERVER_H
#define INOBITEC_TEST_TASK_TCPSERVER_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTimer>

#include "interfaces/IDataGenerator.h"

#define MAX_CLIENTS_COUNT 10
#define BROADCAST_TIMEOUT_MS 1000

class TcpServer: public QObject {
Q_OBJECT
    QTcpServer* pServer;
    IDataGenerator* pDataGenerator;
    QTimer* pBroadcastTimer;

    QSet<QTcpSocket*> clients;

public slots:
    void onNewClient();
    void onClientDisconnected();

    void onSendData();

public:
    explicit TcpServer(QObject* = nullptr);
    ~TcpServer() override;

    inline void setDataGenerator(IDataGenerator *pDataGenerator) { this->pDataGenerator = pDataGenerator; }
    void sendData(const char*, quint32);

    void start(const QHostAddress&, quint16);
    void stop();

private:
    void controlBroadcastTimer();
};


#endif //INOBITEC_TEST_TASK_TCPSERVER_H
