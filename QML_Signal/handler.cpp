#include "handler.h"
#include "qdebug.h"
#include "qvariant.h"

Handler::Handler(QObject *root, QObject *parent) : QObject(parent), m_root(root)
{
    QObject* myButton =  root->findChild<QObject*>("myButton1");
    connect(myButton, SIGNAL(buttonClicked(QString)), this, SLOT(buttonHandler(QString)));

}

void Handler::buttonHandler(QString str)
{
    QObject* pmyText = m_root->findChild<QObject*>("myText1");
    pmyText->setProperty("text", "Thanks!");
    qDebug() << str;
}
