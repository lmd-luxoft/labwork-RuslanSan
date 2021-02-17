#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

#include "bank.h"

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger();

public slots:
    void logAccountChange(long newBalance) const;
    void logTotalBalance(long newTotalBalace) const;
};

#endif // LOGGER_H
