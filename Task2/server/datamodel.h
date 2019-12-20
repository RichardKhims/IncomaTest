#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QMutex>
#include "signletondestroyer.h"

class DataModel: public QObject
{
    Q_OBJECT
private:
   DataModel();
   DataModel(DataModel const&);
   DataModel& operator=(DataModel const&);
   DataModel(DataModel &&other);
   DataModel& operator=(DataModel &&other);

   static DataModel *m_pInstance;
   static SingletonDestroyer<DataModel> destroyer;
public:
   ~DataModel();
   static DataModel *instance();
   void setBlockedValue(const QByteArray &value);
   QByteArray getBlockedValue();
public slots:
   void setValue(QByteArray value);
   void readValue(QByteArray &out);
private:
   QByteArray value;
   QMutex mutex;
};

#endif // DATAMODEL_H
