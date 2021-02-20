#include "datastreamwriter.h"

#include <QFile>
#include <QDataStream>
#include <QDebug>

DataStreamWriter::DataStreamWriter(QString fileName, QObject *parent) : QObject(parent)
{
    // TODO: open file and create QDataStream
    file = new QFile(fileName);
    file->open(QIODevice::WriteOnly);
    stream = new QDataStream(file);

}

DataStreamWriter::~DataStreamWriter()
{
    // TODO: delete stream and file
    delete stream;
    delete file;

}

void DataStreamWriter::writeData(double data)
{
    // TODO: write data to the stream
    *stream << data;
    qDebug() << "Write" << data;
}
