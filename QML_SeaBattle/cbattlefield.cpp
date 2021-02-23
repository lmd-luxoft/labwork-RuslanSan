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
    m_ships.addShip(1, 1, 4, SShip::Horizontal);
    m_ships.addShip(10, 3, 3,SShip::Vertical);
    m_ships.addShip(2, 7, 3, SShip::Horizontal);
    m_ships.addShip(6, 4, 2, SShip::Horizontal);
    m_ships.addShip(8, 8, 2, SShip::Vertical);
    m_ships.addShip(3, 9, 2, SShip::Horizontal);
    m_ships.addShip(1, 3, 1, SShip::Horizontal);
    m_ships.addShip(5, 5, 1, SShip::Horizontal);
    m_ships.addShip(3, 3, 1, SShip::Horizontal);
    m_ships.addShip(8, 6, 1, SShip::Horizontal);

    for (int i=0; i< C_amountOfRows*C_amountOfRows; ++i) {
        m_availableCells.push_back(i);
    }
}

void CBattleField::fire(quint8 x, quint8 y)
{
    quint8 state=1;
    //if (x==3 && y==3)
    //    state = 2;
    if (x>0  &&  y>0  &&  x <= C_amountOfRows  &&  y <= C_amountOfRows) {
        quint8 index = (y-1)*C_amountOfRows + (x-1);
        auto it= std::find( m_firedCells.begin(), m_firedCells.end(), index);
        if (it == m_firedCells.end() ) {
            m_firedCells.push_back(index);
            it= std::find( m_availableCells.begin(), m_availableCells.end(), index);
            if (it != m_availableCells.end())
                m_availableCells.erase(it);

            state = m_ships.getShipStateAtPos(x, y);
            emit setCellValue(x, y, state);
        }
    }
}

quint8 CBattleField::amountOfRows() const
{
    return m_amountOfRows;
}

bool CBattleField::isPlayerComputer() const
{
    return m_playerIsComputer;
}

void CBattleField::setPlayerIsComputer(bool playerIsComputer)
{
    m_playerIsComputer = playerIsComputer;
}

void CBattleField::loadShipsInCells()
{
    //for (auto ship: m_ships) {

    //}
}
