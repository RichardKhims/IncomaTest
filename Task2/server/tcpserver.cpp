#include "tcpserver.h"
#include "clienthandlertthread.h"
#include <QDebug>

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent)
{
}

TcpServer::~TcpServer()
{
    close();
}

void TcpServer::startServer(quint16 port)
{
    if(!this->listen(QHostAddress::Any, port))
    {
        qCritical() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port;
    }
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

    ClientHandlerTthread *thread = new ClientHandlerTthread(socketDescriptor, this);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
