#ifndef CSHIPS_H
#define CSHIPS_H

#include <vector>

struct SShip
{
    enum EShipDirection {Horizontal, Vertical};
    enum EShipState {Absent, Normal, Broken, Destroyed};
    SShip(unsigned char X, unsigned char Y, unsigned char Size, EShipDirection Direction):
        x(X), y(Y), size(Size), direction(Direction), state(0) {};
    unsigned char x;
    unsigned char y;
    unsigned char size;
    EShipDirection direction;
    unsigned char state;
};


class CShips
{
    std::vector<SShip> m_ships;
    unsigned char m_amountOfRowsInBF;
    unsigned char m_amountOfColumnsInBF;
public:
    explicit CShips(unsigned char amountOfRowsInBF, unsigned char amountOfColumnsInBF);
    bool addShip(unsigned char x, unsigned char y, unsigned char size, SShip::EShipDirection direction);
    bool removeShip(unsigned char x, unsigned char y);
    SShip::EShipState getShipStateAtPos(unsigned char x, unsigned char y);
};

#endif // CSHIPS_H
