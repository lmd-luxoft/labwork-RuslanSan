#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human : public QObject
{
    Q_OBJECT
private:
   quint8 m_age;
   char m_sexSymbol;
public:
    explicit Human(QObject *parent = nullptr);
    quint8 age();
    void setAge(quint8 age);
    char sexSymbol();
    void setSexSymbol(char sexSymbol);

signals:

};

#endif // HUMAN_H
