#include <QCoreApplication>
#include "clientbenchmarkthread.h"
#include "benchmarkcalculator.h"
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<ClientBenchmarkThread *> clients;

    for (int i = 0; i < 10; i++) {
        auto client = new ClientBenchmarkThread();
        auto benchmarkCalculator = new BenchmarkCalculator(client);

        QObject::connect(client, SIGNAL(benchmarkStarted()), benchmarkCalculator, SLOT(benchmarkStart()));
        QObject::connect(client, SIGNAL(benchmarkFinished()), benchmarkCalculator, SLOT(benchmarkFinish()));

        clients.push_back(client);
    }

    for (auto client : clients) {
        client->start();
    }

    int res = a.exec();

    qDeleteAll(clients);
    return res;
}
