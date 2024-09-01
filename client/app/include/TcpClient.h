#ifndef INOBITEC_TEST_TASK_TCPCLIENT_H
#define INOBITEC_TEST_TASK_TCPCLIENT_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include "BinFileWriter.h"

class TcpClient final : public QObject {
Q_OBJECT
    QTcpSocket* pSocket;
    QHostAddress serverIp;
    quint16 serverPort;

    IWriter* pWriter;

public slots:
    void onDataReceive();
    void onDisconnected();

public:
    explicit TcpClient(QObject *parent = nullptr);
    ~TcpClient() override;

    void connectToServer(const QHostAddress& serverIp, quint16 serverPort);
    void disconnectFromServer();

    inline void setWriter(IWriter* pWriter) { this->pWriter = pWriter; }
};


#endif //INOBITEC_TEST_TASK_TCPCLIENT_H
