#include "benchmarkcalculator.h"
#include <QDebug>

BenchmarkCalculator::BenchmarkCalculator(QObject *parent) : QObject(parent)
{

}

void BenchmarkCalculator::printResult()
{
    if (end.toTime_t() == 0)
        end = QDateTime::currentDateTime();

    qDebug() << "Benchmark result: " << end.toMSecsSinceEpoch() - start.toMSecsSinceEpoch() << " msec";
}

void BenchmarkCalculator::benchmarkStart()
{
    start = QDateTime::currentDateTime();
}

void BenchmarkCalculator::benchmarkFinish()
{
    end = QDateTime::currentDateTime();
    printResult();
}
