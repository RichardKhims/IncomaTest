#ifndef CLIENTBENCHMARKTHREAD_H
#define CLIENTBENCHMARKTHREAD_H

#include <QThread>
#include <QTcpSocket>

class ClientBenchmarkThread: public QThread
{
    Q_OBJECT
public:
    explicit ClientBenchmarkThread(QObject *parent = 0);

    void run() override;

public slots:
    void threadStarted();
    void readyRead();
    void disconnected();
    void connected();

private:
    QTcpSocket *socket;
    static QByteArray createGetPacket();
    static QByteArray createPutPacket();

    int rcvCount = 0;

signals:
    void benchmarkStarted();
    void benchmarkFinished();
};

#endif // CLIENTBENCHMARKTHREAD_H
