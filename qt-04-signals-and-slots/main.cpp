#include <QCoreApplication>
#include <QDebug>

#include "bank.h"
#include "bankaccount.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bank bank;
    Logger logger;

    BankAccount *account1 = new BankAccount(&bank);
    BankAccount *account2 = new BankAccount(&bank);

    // TODO: connect accounts to the logger
    QObject::connect(
     account1, &BankAccount::balanceChanged,
     &logger, &Logger::logAccountChange
    );


    account1->deposit(1000); // you must be notified about account changes
    account2->deposit(500);  // you must be notified about account changes

    // TODO: connect bank to the logger
    QObject::connect(&bank, &Bank::totalBalanceChanged,
     &logger, &Logger::logTotalBalance);


    account1->withdraw(100); // you must be notified about account changes and that total balance is changed
    account2->withdraw(200); // you must be notified about account changes and that total balance is changed

    return a.exec();
}
