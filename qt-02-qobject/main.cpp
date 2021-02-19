#include <QCoreApplication>
#include <QDebug>
#include "human.h"

void printTreeInfo(QObject *parent)
{
    static unsigned char iNumSpace = 0;

    iNumSpace++;
    // TODO: print here info about all nodes
    Human* human = qobject_cast<Human*>(parent);
    if (human) {
        QString strTab(iNumSpace-1, '\t');
        qDebug() << qPrintable(strTab) << human->objectName()
         << "age:" << human->age()
         << "sex:" << human->sexSymbol();
    }

    for (int i = 0; i < parent->children().length(); ++i) {
        printTreeInfo(human->children().at(i));
    }
    iNumSpace--;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // TODO: create here required hierarchy
     Human *parent = new Human;
     parent->setObjectName("Lucas Grey");
     parent->setAge(54);
     parent->setSexSymbol('M');

     Human *maryGrey = new Human(parent);
     maryGrey->setObjectName("Mary Grey");
     maryGrey->setAge(28);
     maryGrey->setSexSymbol('F');
         Human *fredSmith = new Human(maryGrey);
         fredSmith->setObjectName("Fred Smith");
         fredSmith->setAge(2);
         fredSmith->setSexSymbol('M');
         Human *janeSmith = new Human(maryGrey);
         janeSmith->setObjectName("Jane Smith");
         janeSmith->setAge(2);
         janeSmith->setSexSymbol('F');

     Human *jasonGrey = new Human(parent);
     jasonGrey->setObjectName("Jason Grey");
     jasonGrey->setAge(32);
     jasonGrey->setSexSymbol('M');
         Human *seanGrey = new Human(jasonGrey);
         seanGrey->setObjectName("Sean Grey");
         seanGrey->setAge(5);
         seanGrey->setSexSymbol('F');
         Human *jassicaGrey = new Human(jasonGrey);
         jassicaGrey->setObjectName("Jassica Grey");
         jassicaGrey->setAge(1);
         jassicaGrey->setSexSymbol('F');
         Human *hannahGrey = new Human(jasonGrey);
         hannahGrey->setObjectName("Hannah Grey");
         hannahGrey->setAge(1);
         hannahGrey->setSexSymbol('F');


	// TODO: dump tree info using standard Qt method
	
    printTreeInfo(parent);

    // TODO: delete here what need only
    delete(parent);

    return a.exec();
}
