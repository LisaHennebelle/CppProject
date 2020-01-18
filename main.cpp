
#include <QApplication>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include "Smoke.h"
#include "game.h"
#include "background.h"
#include <QGraphicsView>
#include <unistd.h>
#include<string>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // QGraphicsScene * scene= new QGraphicsScene();

    game * gameS = new game();
  /*  Sac * sac = new Sac();
    Smoke * loco = new Smoke("loco");
    loco->addPixmapnew();
    Smoke * cheminee = new Smoke("cheminee");

    cheminee->addPixmapnew();
    Smoke * cigarette = new Smoke("cigarette");
    cigarette->addPixmapnew();
    //cigarette->associerObj(loco);


    gameS -> addSmoke(*loco);
    gameS -> addSmoke(*cheminee);
    gameS -> addSmoke(*cigarette);
    indice *indice_cigarette = new indice("Ceci est une pipe");
    indice *deuxieme = new indice("Ceci est une flamme");
    indice *troisieme = new indice("Ceci est un smokey butt");
    cigarette->associerIndice(indice_cigarette);
    loco->associerIndice(deuxieme);
    cheminee-> associerIndice(troisieme);

    //loco->setloco(0,0,100,100);
    //cheminee->setloco(0,0,100,100);
    cheminee->setPos(cheminee->x()+200, cheminee->y()+300);
   // cigarette->setloco(0,0,50,50);
    cigarette->setPos(cigarette->x()+400, cigarette->y());


    //sac->addObject(*loco);

    // /* scene->addItem(loco);
    scene->addItem(cheminee);
    scene->addItem(sac);
    // scene->addItem(cigarette);/


    //make loco focusable
    loco->setFlag(QGraphicsItem::ItemIsFocusable);
    loco->setFocus();

    cheminee->setFlag(QGraphicsItem::ItemIsFocusable);
    cheminee->setFocus();

    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();

    cigarette->setFlag(QGraphicsItem::ItemIsFocusable);
    cigarette->setFocus();*/

    QGraphicsView * view = new QGraphicsView(gameS->scenery);
    //gameS->scenery->addItem(sac);
    //view->
    view ->resize(1500, 900);
    gameS->testGame();
    view->show();
    /*if (cheminee->getFlag()==1)
    {
        sac->addObject(*cheminee);
    }*/
    // indice_cigarette->show();


    return a.exec();
}
