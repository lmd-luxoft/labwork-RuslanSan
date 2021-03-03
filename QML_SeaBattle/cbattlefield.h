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
    Q_PROPERTY(bool playerIsComputer READ isPlayerComputer WRITE setPlayerIsComputer NOTIFY PlayerIsComputerChanged);
    Q_PROPERTY(quint8 amountOfRows READ amountOfRows CONSTANT);
    Q_PROPERTY(quint8 amountOfShips READ amountOfShips CONSTANT);
    Q_PROPERTY(quint8 amountOfDestroyedShips READ amountOfDestroyedShips);
    Q_INVOKABLE void fire(quint8 x, quint8 y);

    quint8 amountOfRows() const;
    quint8 amountOfShips() const;
    quint8 amountOfDestroyedShips() const;

    bool isPlayerComputer() const;
    void setPlayerIsComputer(bool playerIsComputer);
    void showShipInState(const CShip* pShip, quint8 state);
    void showShips();
    CShips& ships();
    const std::vector<quint8>& availableCells() const;

signals:
    void setCellValue(quint8 x, quint8 y, quint8 state);
    void shipDestroyed();
    void allShipDestroyed();
    void PlayerIsComputerChanged(bool playerIsComputer);
    void afterFire(bool currentPlayerIsHuman);

private:

private:
    quint8 m_amountOfRows;
    bool m_playerIsComputer;
    std::vector<quint8> m_availableCells; //array of not fired BattleField cells
    std::vector<quint8> m_firedCells; //array of fired BattleField cells
    CShips m_ships;
};

#endif // CBATTLEFIELD_H
