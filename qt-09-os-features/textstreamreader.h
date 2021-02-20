#ifndef TEXTSTREAMREADER_H
#define TEXTSTREAMREADER_H

#include <QObject>

class TextStreamReader : public QObject
{
    Q_OBJECT
public:
    explicit TextStreamReader(QObject *parent = 0);

    void readFromFile(QString fileName);
signals:
    void dataReaded(double price);
    void allDataReaded();
public slots:
};

#endif // TEXTSTREAMREADER_H
