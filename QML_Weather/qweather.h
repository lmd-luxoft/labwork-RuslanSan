#ifndef QWEATHER_H
#define QWEATHER_H

#include <QObject>
#include <QString>

class Qweather : public QObject
{
    Q_OBJECT
public:
    explicit Qweather(QObject *parent = nullptr);
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged);
    Q_PROPERTY(QString currentWeather READ processWeather);
    Q_INVOKABLE void forceUpdate();
    QString city();
    void setCity(QString city);
signals:
    void cityChanged();
    void weatherChanged(QString);
private:
    QString m_city;
    QString m_weather;
    QString processWeather();
};

#endif // QWEATHER_H
