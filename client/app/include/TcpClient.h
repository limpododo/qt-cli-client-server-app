#ifndef INOBITEC_TEST_TASK_TCPCLIENT_H
#define INOBITEC_TEST_TASK_TCPCLIENT_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include "BinFileWriter.h"

class TcpClient : public QObject {
Q_OBJECT
    /* Network fields */
    QTcpSocket* pSocket;
    QHostAddress serverIp{};
    quint16 serverPort{};

    /* File writer fields */
    IWriter* pWriter;
public slots:
    void onDataReceive();
    void onDisconnected();
public:
    explicit TcpClient(QObject *parent = nullptr);
    ~TcpClient() override;

    void connectToServer(const QHostAddress&, const quint16);
    void disconnectFromServer();

    void setWriter(IWriter* writer);
};


#endif //INOBITEC_TEST_TASK_TCPCLIENT_H
