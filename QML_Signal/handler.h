#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QString>

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *root, QObject *parent = nullptr);

public slots:
    void buttonHandler(QString str);

private:
    QObject *m_root;

};

#endif // HANDLER_H
