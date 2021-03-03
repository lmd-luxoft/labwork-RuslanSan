#ifndef CPLAYERS_H
#define CPLAYERS_H

#include <QObject>
#include <cship.h>
#include "cships.h"
#include "cbattlefield.h"

class CPlayers : public QObject
{
    Q_OBJECT
public:
    explicit CPlayers(QObject *root, QObject *parent = nullptr);
    void putShips();

signals:

public slots:
    void computerFire(bool currentPlayerIsHuman);

private:
    QObject* m_pRoot;
    CBattleField* m_pBF_Human;
    CBattleField* m_pBF_Computer;
};

#endif // CPLAYERS_H
