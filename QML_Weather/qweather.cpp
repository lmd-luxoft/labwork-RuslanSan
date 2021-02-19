#include "qweather.h"
#include "random"

Qweather::Qweather(QObject *parent) : QObject(parent)
{

}

void Qweather::forceUpdate()
{
    if (m_city.compare("Saint Peterburg") == 0)
    {
        m_weather = "Температура = -" + QString::number(std::rand() % 20) + " градусов";
    }
    else if (m_city.compare("Odessa") == 0)
    {
        m_weather = "Температура = +" + QString::number(std::rand() % 20) + " градусов";
    }
    else
        m_weather = "No city found";

    emit weatherChanged(m_weather);
}

QString Qweather::city()
{
    return m_city;
}

void Qweather::setCity(QString city)
{
    m_city = city;
}

QString Qweather::processWeather()
{
    return m_weather;
}
