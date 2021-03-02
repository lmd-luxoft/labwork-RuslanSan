#include "cships.h"
#include <algorithm>

CShips::CShips(unsigned char amountOfRowsInBF, unsigned char amountOfColumnsInBF):
    m_amountOfRowsInBF(amountOfRowsInBF), m_amountOfColumnsInBF(amountOfColumnsInBF)
{

}

bool CShips::addShip(unsigned char x, unsigned char y, unsigned char size, CShip::EShipDirection direction)
{
    bool bResult = false; //to check if position and size of ship are inside battlefield

    if ( direction == CShip::Horizontal && ((x+size)<=(m_amountOfColumnsInBF+1)) && (y<=m_amountOfRowsInBF) )  {
        m_ships.push_back( CShip(x, y, size, direction) );
        bResult = true;
    }
    if ( direction == CShip::Vertical && ((y+size)<=(m_amountOfRowsInBF+1)) && (x<=m_amountOfColumnsInBF) )  {
        m_ships.push_back( CShip(x, y, size, direction) );
        bResult = true;
    }
    return bResult;
}

bool CShips::removeShip(unsigned char x, unsigned char y)
{
    bool bResult = true;
    if (isShipPresentAtPos(x,y)) {
        std::vector<CShip>::iterator it = std::find_if(m_ships.begin(), m_ships.end(),
                                                       [x,y] (const CShip& ship) { return (x==ship.x() && y==ship.y()); });
        if(it != m_ships.end()) m_ships.erase(it);
    }
    return bResult;
}

const std::vector<CShip>& CShips::ships() const
{
    return m_ships;
}

CShip* CShips::isShipPresentAtPos(unsigned char x, unsigned char y)
{
    CShip* pShip=nullptr;
    for (auto &ship: m_ships)
    {
        if (ship.direction() == CShip::Horizontal) {
            if ( ((x >= ship.x()) && ( x < (ship.x()+ship.size()))) && ship.y() ==y) {
                pShip = &ship;
                break;
            }
        }
        else
            if ( ((y >= ship.y()) && ( y < (ship.y()+ship.size()))) && ship.x() ==x){
                pShip = &ship;
                break;
            }
    }
    return pShip;
}

unsigned char CShips::amountOfShips() const
{
    return m_ships.size();
}

unsigned char CShips::amountOfDestoyedShips() const
{
    return std::count_if(m_ships.begin(), m_ships.end(),
                  [] (const CShip& ship) { return (CShip::Destroyed==ship.state()); });
}
