
#include <QApplication>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include "code.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene= new QGraphicsScene();

    Objet * rect = new Objet();
    rect->setName("clé");
    Objet * rect2 = new Objet();
    Code * cadenas = new Code("Cadenas");
    cadenas->associerObj(*rect);
    Sac * sac = new Sac();

    rect->setRect(0,0,100,100);
    rect2->setRect(0,0,100,100);
    rect2->setPos(rect2->x()-200, rect2->y()-300);
    cadenas->setRect(0,0,50,50);
    cadenas->setPos(cadenas->x()-350, cadenas->y()-350);

    //sac->addObject(*rect);

    scene->addItem(rect);
    scene->addItem(rect2);
    scene-> addItem(sac);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    rect2->setFlag(QGraphicsItem::ItemIsFocusable);
    rect2->setFocus();

    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();



    return a.exec();
}
