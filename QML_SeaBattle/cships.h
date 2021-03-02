#ifndef CSHIPS_H
#define CSHIPS_H

#include <cship.h>
#include <vector>


class CShips
{
    std::vector<CShip> m_ships;
    const unsigned char m_amountOfRowsInBF;
    const unsigned char m_amountOfColumnsInBF;
public:
    explicit CShips(unsigned char amountOfRowsInBF, unsigned char amountOfColumnsInBF);
    bool addShip(unsigned char x, unsigned char y, unsigned char size, CShip::EShipDirection direction);
    bool removeShip(unsigned char x, unsigned char y);
    const std::vector<CShip>& ships() const;
    //SShip::EShipState getShipStateAtPos(unsigned char x, unsigned char y) const;
    CShip* isShipPresentAtPos(unsigned char x, unsigned char y);
    unsigned char amountOfShips()  const;
    unsigned char amountOfDestoyedShips()  const;
};

#endif // CSHIPS_H
