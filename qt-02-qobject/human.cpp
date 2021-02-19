#include "human.h"

Human::Human(QObject *parent) : QObject(parent)
{

}

quint8 Human::age()
{
    return m_age;
}

void Human::setAge(quint8 age)
{
    m_age = age;
}

char Human::sexSymbol()
{
    return m_sexSymbol;
}

void Human::setSexSymbol(char sexSymbol)
{
    m_sexSymbol = sexSymbol;
}
