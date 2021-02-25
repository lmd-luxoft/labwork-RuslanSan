#include "cships.h"

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
    bool bResult = true; //to check if position and size of ship are inside battlefield
   // m_ships.find
    //m_ships.remove
    if (x && y) bResult = true;
    return bResult;
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

unsigned char CShip::x() const
{
    return m_x;
}

unsigned char CShip::y() const
{
    return m_y;
}

unsigned char CShip::size() const
{
    return m_size;
}

CShip::EShipDirection CShip::direction() const
{
    return m_direction;
}

CShip::EShipState CShip::state() const
{
    CShip::EShipState state = m_amountNotDestroyedParts ? Broken: Destroyed;
    return  (m_size-m_amountNotDestroyedParts)  ? state : Normal;
}

void CShip::DestroyOnePart()
{
    if (m_amountNotDestroyedParts) --m_amountNotDestroyedParts;
}
