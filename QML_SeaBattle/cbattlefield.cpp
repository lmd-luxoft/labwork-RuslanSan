#include "cbattlefield.h"
#include "cships.h"
#include <algorithm>

const quint8 C_amountOfRows = 10;


CBattleField::CBattleField(QObject *parent) : QObject(parent),
    m_amountOfRows(C_amountOfRows),
    m_playerIsComputer(false),
    m_availableCells(),
    m_firedCells(),
    m_ships(C_amountOfRows, C_amountOfRows)
{
    for (int i=0; i< C_amountOfRows*C_amountOfRows; ++i) {
        m_availableCells.push_back(i);
    }
}

CShips& CBattleField::ships() {
    return m_ships;
}


void CBattleField::fire(quint8 x, quint8 y)
{
    quint8 state=CShip::Undefined;

    if (x>0  &&  y>0  &&  x <= C_amountOfRows  &&  y <= C_amountOfRows) {
        quint8 index = (y-1)*C_amountOfRows + (x-1);
        auto it= std::find( m_firedCells.begin(), m_firedCells.end(), index);
        if (it == m_firedCells.end() ) {
            m_firedCells.push_back(index);
            it= std::find( m_availableCells.begin(), m_availableCells.end(), index);
            if (it != m_availableCells.end())
                m_availableCells.erase(it);

            CShip* pShip = m_ships.isShipPresentAtPos(x, y);
            if (pShip) {
                pShip->DestroyOnePart();
                state = (pShip->state() != CShip::Destroyed) ? CShip::Broken : CShip::Destroyed;
                if (CShip::Destroyed == state) {
                    showShipInState( pShip, CShip::Destroyed);

                    emit shipDestroyed();
                    if (m_ships.amountOfDestoyedShips() == m_ships.amountOfShips())
                        emit allShipDestroyed();
                }
            }
            if (CShip::Destroyed != state)
                emit setCellValue(x, y, state);
        }
    }
}

quint8 CBattleField::amountOfRows() const
{
    return m_amountOfRows;
}

quint8 CBattleField::amountOfShips() const
{
    return m_ships.amountOfShips();
}

quint8 CBattleField::amountOfDestroyedShips() const
{
    return m_ships.amountOfDestoyedShips();
}

bool CBattleField::isPlayerComputer() const
{
    return m_playerIsComputer;
}

void CBattleField::setPlayerIsComputer(bool playerIsComputer)
{
    m_playerIsComputer = playerIsComputer;
}

void CBattleField::showShipInState(const CShip *pShip, quint8 state)
{
    if (pShip) {
        quint8 xd(0), yd(0);
        for (auto i=0; i<pShip->size(); i++) {
            if (CShip::Horizontal == pShip->direction()) {
                xd=i; }
            else {
                yd=i; }
            emit setCellValue(pShip->x()+xd, pShip->y()+yd, state);
        }
    }
}

void CBattleField::showShips()
{
    for(const CShip ship: m_ships.ships()) {
        showShipInState( &ship, CShip::Normal);
    }
}

//void CBattleField::loadShipsInCells()
//{
//    //for (auto ship: m_ships) {

//    //}
//}

//void CBattleField::markShipsAsDestroyed()
//{

//    //for (int i=0; )
//    //    void setCellValue(quint8 x, quint8 y, quint8 state);

//}
