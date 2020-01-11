
#include <QApplication>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include "code.h"
#include <QGraphicsView>
#include <unistd.h>
#include<string>


/*#include <QtTest/QtTest>
#include <QtTest/QTestKeyClicksEvent>
#include <QtTest/QtTestDepends>
#include <QtTest/qtest.h>

#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
void QTest::qSleep(int ms)
{
    QTEST_ASSERT(ms > 0);

#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene= new QGraphicsScene();
    Objet * rect = new Objet("clé");
    //rect->setName("clé");
    Objet * rect2 = new Objet();
    Code * cadenas = new Code("cadenas");
    cadenas->associerObj(rect);
    Sac * sac = new Sac();

    if (rect -> MouseEvent(event) == 1);
    sac -> addObject(*rect);
    indice *indice_cadenas = new indice("trouvez la clé");
    cadenas->associerIndice(indice_cadenas);

    rect->setRect(0,0,100,100);
    rect2->setRect(0,0,100,100);
    rect2->setPos(rect2->x()+200, rect2->y()+300);
    cadenas->setRect(0,0,50,50);
    cadenas->setPos(cadenas->x()+400, cadenas->y());


    //sac->addObject(*rect);

    scene->addItem(rect);
    scene->addItem(rect2);
    scene-> addItem(sac);
    scene-> addItem(cadenas);


    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    rect2->setFlag(QGraphicsItem::ItemIsFocusable);
    rect2->setFocus();

    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();

    cadenas->setFlag(QGraphicsItem::ItemIsFocusable);
    cadenas->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view ->resize(1500, 1000);
    view->show();


     usleep(5);
    // QTest::qSleep(100);
    indice_cadenas->show();


    return a.exec();
}
