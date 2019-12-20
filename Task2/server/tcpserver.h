#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include "clienthandlertthread.h"

class TcpServer: public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    ~TcpServer();
    void startServer(quint16 port);
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor) override;

};

#endif // TCPSERVER_H
