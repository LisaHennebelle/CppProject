
#include <QApplication>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include "Smoke.h"
#include <QGraphicsView>
#include <unistd.h>
#include<string>






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene= new QGraphicsScene();
    Sac * sac = new Sac();
    Smoke * rect = new Smoke("clé");
    //rect->setName("clé");
    Smoke * rect2 = new Smoke();
    Smoke * cadenas = new Smoke("cadenas");
    //cadenas->associerObj(rect);


    sac -> addObject(*rect);
    indice *indice_cadenas = new indice("Ceci est une pipe");
    cadenas->associerIndice(indice_cadenas);

    rect->setRect(0,0,100,100);
    rect2->setRect(0,0,100,100);
    rect2->setPos(rect2->x()+200, rect2->y()+300);
    cadenas->setRect(0,0,50,50);
    cadenas->setPos(cadenas->x()+400, cadenas->y());


    //sac->addObject(*rect);

    scene->addItem(rect);
    scene->addItem(rect2);
    scene->addItem(sac);
    scene->addItem(cadenas);


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
    /*if (rect2->getFlag()==1)
    {
        sac->addObject(*rect2);
    }*/
    view->show();
   // indice_cadenas->show();


    return a.exec();
}
