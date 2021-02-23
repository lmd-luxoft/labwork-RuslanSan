#include "cships.h"

CShips::CShips(unsigned char amountOfRowsInBF, unsigned char amountOfColumnsInBF):
    m_amountOfRowsInBF(amountOfRowsInBF), m_amountOfColumnsInBF(amountOfColumnsInBF)
{

}

bool CShips::addShip(unsigned char x, unsigned char y, unsigned char size, SShip::EShipDirection direction)
{
    bool bResult = false; //to check if position and size of ship are inside battlefield

    if ( direction == SShip::Horizontal && ((x+size)<=(m_amountOfColumnsInBF+1)) && (y<=m_amountOfRowsInBF) )  {
        m_ships.push_back( SShip(x, y, size, direction) );
        bResult = true;
    }
    if ( direction == SShip::Vertical && ((y+size)<=(m_amountOfRowsInBF+1)) && (x<=m_amountOfColumnsInBF) )  {
        m_ships.push_back( SShip(x, y, size, direction) );
        bResult = true;
    }
    return bResult;
}

bool CShips::removeShip(unsigned char x, unsigned char y)
{
    bool bResult = true; //to check if position and size of ship are inside battlefield
   // m_ships.find
    //m_ships.remove
    if (x && y) bResult = true;
    return bResult;
}

SShip::EShipState CShips::getShipStateAtPos(unsigned char x, unsigned char y)
{
    SShip::EShipState state=SShip::Absent;
    for (auto ship: m_ships)
    {
        if (ship.direction == SShip::Horizontal) {
            if ( ((x >= ship.x) && ( x < (ship.x+ship.size))) && ship.y ==y)
                state=SShip::Normal;
        }
        else {
            if ( ((y >= ship.y) && ( y < (ship.y+ship.size))) && ship.x ==x)
                state=SShip::Normal;
        }

    }
    return state;
}
