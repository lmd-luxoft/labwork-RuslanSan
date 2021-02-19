#include "logger.h"
#include <QDebug>

Logger::Logger() : QObject()
{

}

void Logger::logAccountChange(long newBalance) const
{
    qDebug() << QString("New Balance: %1").arg(newBalance);
}

void Logger::logTotalBalance(long newTotalBalance) const
{
    qDebug() << QString("New Total Balance: %1").arg(newTotalBalance);
}
