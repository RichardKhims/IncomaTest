#include "datamodel.h"

SingletonDestroyer<DataModel> DataModel::destroyer;
DataModel* DataModel::m_pInstance = nullptr;

DataModel::DataModel()
{

}

DataModel::~DataModel()
{

}

DataModel *DataModel::instance()
{
    if (!m_pInstance)
        m_pInstance = new DataModel();

    return m_pInstance;
}

void DataModel::setBlockedValue(const QByteArray &value)
{
    mutex.lock();
    setValue(value);
    mutex.unlock();
}

QByteArray DataModel::getBlockedValue()
{
    QByteArray ba;

    mutex.lock();
    ba.append(value);
    mutex.unlock();

    return ba;
}

void DataModel::setValue(QByteArray value)
{
    this->value.clear();
    this->value.append(value);
}

void DataModel::readValue(QByteArray &out)
{
    out.clear();
    out.append(value);
}
