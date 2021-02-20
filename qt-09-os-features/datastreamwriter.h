#ifndef DATASTREAMWRITER_H
#define DATASTREAMWRITER_H

#include <QObject>

class DataStreamWriter : public QObject
{
    Q_OBJECT
public:
    explicit DataStreamWriter(QString fileName, QObject *parent = 0);
    ~DataStreamWriter();
signals:

public slots:
    void writeData(double data);

private:
    class QFile *file;
    class QDataStream *stream;
};

#endif // DATASTREAMWRITER_H
