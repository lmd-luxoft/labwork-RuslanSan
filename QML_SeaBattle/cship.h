#ifndef CSHIP_H
#define CSHIP_H

class CShip
{
public:
    enum EShipDirection {Horizontal, Vertical};
    enum EShipState {Undefined, Normal, Broken, Destroyed};
    CShip(unsigned char x, unsigned char y, unsigned char size, EShipDirection direction);;
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


#endif // CSHIP_H
