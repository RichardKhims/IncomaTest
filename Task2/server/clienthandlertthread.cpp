#include "clienthandlertthread.h"
#include <QDebug>

ClientHandlerTthread::ClientHandlerTthread(qintptr ID, QObject *parent) :
    QThread(parent), socketDescriptor(ID)
{
    connect(this, SIGNAL(started()), this, SLOT(threadStarted()));
}

ClientHandlerTthread::~ClientHandlerTthread()
{
    socket->close();
}

void ClientHandlerTthread::run()
{
    qDebug() << "Start handler thread";

    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socketDescriptor << " Client connected";

    exec();
}

void ClientHandlerTthread::readyRead()
{
    while (socket->bytesAvailable()) {
        auto data = socket->readLine();

//        qDebug() << currentThreadId() << socketDescriptor << " Data in: " << data << "\n";

        if (QString(data).contains("GET")) {
//            data = DataModel::instance()->getBlockedValue();
            emit readData(data);
            socket->write(data);
        } else {
//            DataModel::instance()->setBlockedValue(data);
            emit changeData(data);
        }
    }
}

void ClientHandlerTthread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";

    socket->deleteLater();
    exit(0);
}

void ClientHandlerTthread::threadStarted()
{
    connect(this, SIGNAL(changeData(QByteArray)), DataModel::instance(), SLOT(setValue(QByteArray)));
    connect(this, SIGNAL(readData(QByteArray&)), DataModel::instance(), SLOT(readValue(QByteArray&)), Qt::BlockingQueuedConnection);
}
