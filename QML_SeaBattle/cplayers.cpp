#include "cplayers.h"
#include "cbattlefield.h"
#include "random"

CPlayers::CPlayers(QObject *root, QObject *parent) : QObject(parent), m_pRoot(root), m_pBF_Human(nullptr), m_pBF_Computer(nullptr)
{
    QObject* pBF =  root->findChild<QObject*>("BattleField_Player");
    if (pBF)
    {
        pBF =  pBF->findChild<QObject*>("BF");
        m_pBF_Human = qobject_cast<CBattleField*>(pBF);
//        QObject *rect = object->findChild<QObject*>("rect");
//         if (rect)
//             rect->setProperty("color", "red");

//        if (m_pBF_Human) {
//            connect(m_pBF_Human, SIGNAL(afterFire(bool)), this, SLOT(computerFire(bool)));
//        }
    }
    pBF =  root->findChild<QObject*>("BattleField_Computer");
    if (pBF)
    {
        pBF =  pBF->findChild<QObject*>("BF");
        m_pBF_Computer = qobject_cast<CBattleField*>(pBF);
        if (m_pBF_Computer) {
            connect(m_pBF_Computer, SIGNAL(afterFire(bool)), this, SLOT(computerFire(bool)));
        }
    }

    putShips();
}

void CPlayers::putShips()
{
    if (m_pBF_Human) {
        m_pBF_Human->ships().addShip(1, 1, 4, CShip::Horizontal);
        m_pBF_Human->ships().addShip(10, 3, 3,CShip::Vertical);
        m_pBF_Human->ships().addShip(2, 7, 3, CShip::Horizontal);
        m_pBF_Human->ships().addShip(6, 4, 2, CShip::Horizontal);
        m_pBF_Human->ships().addShip(8, 8, 2, CShip::Vertical);
        m_pBF_Human->ships().addShip(3, 9, 2, CShip::Horizontal);
        m_pBF_Human->ships().addShip(1, 3, 1, CShip::Horizontal);
        m_pBF_Human->ships().addShip(5, 5, 1, CShip::Horizontal);
        m_pBF_Human->ships().addShip(3, 3, 1, CShip::Horizontal);
        m_pBF_Human->ships().addShip(8, 6, 1, CShip::Horizontal);
        m_pBF_Human->showShips();
    }

    if (m_pBF_Computer) {
        m_pBF_Computer->ships().addShip(5, 10, 4, CShip::Horizontal);
        m_pBF_Computer->ships().addShip(1, 3, 3,CShip::Vertical);
        m_pBF_Computer->ships().addShip(7, 6, 3, CShip::Vertical);
        m_pBF_Computer->ships().addShip(6, 1, 2, CShip::Horizontal);
        m_pBF_Computer->ships().addShip(9, 8, 2, CShip::Vertical);
        m_pBF_Computer->ships().addShip(2, 9, 2, CShip::Horizontal);
        m_pBF_Computer->ships().addShip(7, 3, 1, CShip::Horizontal);
        m_pBF_Computer->ships().addShip(5, 5, 1, CShip::Horizontal);
        m_pBF_Computer->ships().addShip(3, 3, 1, CShip::Horizontal);
        m_pBF_Computer->ships().addShip(10, 4, 1, CShip::Horizontal);
    }
}

void CPlayers::computerFire(bool currentPlayerIsHuman)
{
    if ( currentPlayerIsHuman && m_pBF_Human)    {

        const auto arraySize = m_pBF_Human->availableCells().size();
        auto index = std::rand() % (arraySize);
        if (1 == arraySize) index = 0;
        const quint8 cellIndex = m_pBF_Human->availableCells().at(index);
        //quint8 index = (y-1)*C_amountOfRows + (x-1);
        quint8 y = (cellIndex / C_amountOfRows) + 1;
        quint8 x = (cellIndex % C_amountOfRows) + 1;

        m_pBF_Human->fire(x, y);
    }
}

