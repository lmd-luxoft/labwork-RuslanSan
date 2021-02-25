#ifndef CSHIPS_H
#define CSHIPS_H

#include <vector>

class CShip
{
public:
    enum EShipDirection {Horizontal, Vertical};
    enum EShipState {Undefined, Normal, Broken, Destroyed};
    CShip(unsigned char x, unsigned char y, unsigned char size, EShipDirection direction):
        m_x(x), m_y(y), m_size(size), m_direction(direction), m_amountNotDestroyedParts(size) {};
    unsigned char x() const;
    unsigned char y() const;
    unsigned char size() const;
    EShipDirection direction() const;
    EShipState state() const;
    void DestroyOnePart();
private:
    unsigned char m_x;
    unsigned char m_y;
    unsigned char m_size;
    EShipDirection m_direction;
    unsigned char m_amountNotDestroyedParts;
};


class CShips
{
    std::vector<CShip> m_ships;
    unsigned char m_amountOfRowsInBF;
    unsigned char m_amountOfColumnsInBF;
public:
    explicit CShips(unsigned char amountOfRowsInBF, unsigned char amountOfColumnsInBF);
    bool addShip(unsigned char x, unsigned char y, unsigned char size, CShip::EShipDirection direction);
    bool removeShip(unsigned char x, unsigned char y);
    //SShip::EShipState getShipStateAtPos(unsigned char x, unsigned char y) const;
    CShip* isShipPresentAtPos(unsigned char x, unsigned char y);

};

#endif // CSHIPS_H
