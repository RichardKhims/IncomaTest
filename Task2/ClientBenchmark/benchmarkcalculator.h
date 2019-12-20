#ifndef BENCHMARKCALCULATOR_H
#define BENCHMARKCALCULATOR_H

#include <QObject>
#include <QDateTime>

class BenchmarkCalculator : public QObject
{
    Q_OBJECT

private:
    QDateTime start;
    QDateTime end = QDateTime::fromTime_t(0);

public:
    explicit BenchmarkCalculator(QObject *parent = 0);
signals:

public slots:
    void benchmarkStart();
    void benchmarkFinish();

private:
    void printResult();
};

#endif // BENCHMARKCALCULATOR_H
