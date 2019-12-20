#include "clientbenchmarkthread.h"
#include <QDebug>
#include <QUuid>
#include <QDateTime>
#include <QCryptographicHash>

ClientBenchmarkThread::ClientBenchmarkThread(QObject *parent) :
    QThread(parent)
{
    connect(this, SIGNAL(started()), this, SLOT(threadStarted()));
}

void ClientBenchmarkThread::run()
{
    socket = new QTcpSocket();

    connect(socket, SIGNAL(connected()), this, SLOT(connected()), Qt::DirectConnection);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    exec();
}

void ClientBenchmarkThread::threadStarted()
{
    socket->connectToHost("localhost", 1234);
}

void ClientBenchmarkThread::readyRead()
{
    while (socket->bytesAvailable()) {
        QByteArray answer = socket->readLine();
        rcvCount++;
//        qDebug() << socket->socketDescriptor() << " Actual value: " << answer << rcvCount;
    }
    if (rcvCount == 90)
        emit benchmarkFinished();
}

void ClientBenchmarkThread::disconnected()
{
    socket->deleteLater();
    exit(0);
}

void ClientBenchmarkThread::connected()
{
    auto getPacket = createGetPacket();

    emit benchmarkStarted();

    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            auto putPacket = createPutPacket();
            socket->write(putPacket);
        } else
            socket->write(getPacket);
    }
}

QByteArray ClientBenchmarkThread::createGetPacket()
{
    char endLine = '\n';
    QByteArray getPacket("GET");
    getPacket.append(endLine);

    return getPacket;
}

QByteArray ClientBenchmarkThread::createPutPacket()
{
    char endLine = '\n';
    QByteArray putPacket;
    putPacket.append(QUuid::createUuid().toByteArray());
    putPacket.append(endLine);

    return putPacket;
}
