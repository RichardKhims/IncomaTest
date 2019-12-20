#ifndef CLIENTHANDLERTTHREAD_H
#define CLIENTHANDLERTTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include "datamodel.h"

class ClientHandlerTthread: public QThread
{
    Q_OBJECT
public:
    explicit ClientHandlerTthread(qintptr ID, QObject *parent = 0);
    ~ClientHandlerTthread();

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketerror);
    void changeData(QByteArray);
    void readData(QByteArray&);

public slots:
    void readyRead();
    void disconnected();
    void threadStarted();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // CLIENTHANDLERTTHREAD_H
