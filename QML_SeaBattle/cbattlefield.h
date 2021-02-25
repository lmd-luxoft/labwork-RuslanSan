#ifndef CBATTLEFIELD_H
#define CBATTLEFIELD_H

#include <QObject>
#include <vector>
#include "cships.h"

extern const quint8 C_amountOfRows;

class CBattleField : public QObject
{
    Q_OBJECT
public:
    explicit CBattleField(QObject *parent = nullptr);
    //Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged);
    Q_PROPERTY(bool playerIsComputer READ isPlayerComputer WRITE setPlayerIsComputer);// NOTIFY PlayerIsComputerChanged);
    Q_PROPERTY(quint8 amountOfRows READ amountOfRows CONSTANT);
    Q_INVOKABLE void fire(quint8 x, quint8 y);
    //Q_PROPERTY(quint8 amountOfCells READ amountOfCells CONSTANT);

    quint8 amountOfRows() const;

    bool isPlayerComputer() const;
    void setPlayerIsComputer(bool playerIsComputer);

//    quint8 amountOfCells() const
//    {
//        return static_cast<quint8>( m_cells.size() );
//    }

signals:
    void setCellValue(quint8 x, quint8 y, quint8 state);
    //void PlayerIsComputerChanged(bool playerIsComputer);

private:
    void loadShipsInCells();
    void markShipsAsDestroyed();

private:
    quint8 m_amountOfRows;
    bool m_playerIsComputer;
    std::vector<quint8> m_availableCells; //array of not fired BattleField cells
    std::vector<quint8> m_firedCells; //array of fired BattleField cells
    CShips m_ships;
};

#endif // CBATTLEFIELD_H
