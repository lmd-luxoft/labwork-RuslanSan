#include "cship.h"

CShip::CShip(unsigned char x, unsigned char y, unsigned char size, CShip::EShipDirection direction):
    m_x(x), m_y(y), m_size(size), m_direction(direction), m_amountNotDestroyedParts(size)
{

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
