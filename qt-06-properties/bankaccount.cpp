#include "bankaccount.h"

BankAccount::BankAccount(QObject *parent) : QObject(parent)
{
    m_balance = 5000;
}

void BankAccount::deposit(long amount)
{
    m_balance += amount;
}

void BankAccount::withdraw(long amount)
{
    m_balance -= amount;
}

QString BankAccount::holderName()
{
    return m_holderName;
}

void BankAccount::setHolderName(QString name)
{
    m_holderName = name;
}

long BankAccount::balance()
{
    return m_balance;
}
