#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include <QList>
#include <list>

game::game()
{
    // taille des listes imposée
    items->resize(NUM_OBJET);
    smokey_items->resize(NUM_SMOKE);
    mb->setText("GAME OVER");

    // création des objets
    QString a = "A";
    int  i = 0;
    for (i = 0 ; i <NUM_OBJET ; i++) // remplissage de la liste des objets
    {
        QString name = "objet_ "+ a ;
        a = a+1;
        Objet *o = new Objet(name);
        items->push_back(*o);
        qDebug() << "ajout de l'objet : "<< o->getName();
        background *bg = new background();
        scenery->addItem(bg);
    }
    over = 0;
    // creation des variables sac loco, cheminee et cigarette
    Sac * sac = new Sac();

    //creation des objets smoke
    Smoke * loco = new Smoke("loco");
    loco->addPixmapnew();
    Smoke * cheminee = new Smoke("cheminee");
    cheminee->addPixmapnew();
    Smoke * cigarette = new Smoke("cigarette");
    cigarette->addPixmapnew();
    // set location
    loco->setPos(loco->x()+10, loco->y()+20);
    cheminee->setPos(cheminee->x()+200, cheminee->y()+300);
    cigarette->setPos(cigarette->x()+400, cigarette->y());

    //make them focusable
    loco->setFlag(QGraphicsItem::ItemIsFocusable);
    loco->setFocus();

    cheminee->setFlag(QGraphicsItem::ItemIsFocusable);
    cheminee->setFocus();

    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();

    cigarette->setFlag(QGraphicsItem::ItemIsFocusable);
    cigarette->setFocus();

    // ajout des indices
    indice *indice_cigarette = new indice("Ceci est une pipe");
    indice *deuxieme = new indice("Ceci est une flamme");
    indice *troisieme = new indice("Ceci est un smokey butt");
    cigarette->associerIndice(indice_cigarette);
    loco->associerIndice(deuxieme);
    cheminee-> associerIndice(troisieme);

    //ajout a la scene
    scenery->addItem(sac);
    scenery->addItem(loco);
    scenery->addItem(cheminee);
    scenery->addItem(cigarette);

    // ajout a la liste de game
    smokey_items ->push_back(loco);
    qDebug() << "loco pos: x = " << loco->x() << "et y = " << loco ->y();
   qDebug() << "loco_items pos: x = " << (*smokey_items->begin())->x() << "et y = " <<(*smokey_items->begin())->y();
    smokey_items->push_back(cheminee);
    qDebug() << "cheminee pos: x = " << cheminee->x() << "et y = " << cheminee ->y();
    smokey_items->push_back(cigarette);
    qDebug() << "cigarette pos: x = " << cigarette->x() << "et y = " << loco ->y();
    qDebug()<<"game created";
}
game::~game()
{
    qDebug()<<"game finished";
    //eliminitaion de tous les elements de la liste items
    for (std::list<Objet>::iterator it_o=items->begin(); it_o !=items->end(); ++it_o)
    {
        items -> erase(it_o);
    }
    // elimination de tous les elements de la liste smokey_items
    for (std::vector<Smoke*>::iterator it=smokey_items->begin(); it !=smokey_items->end(); ++it)
    {
    smokey_items -> erase(it);
    }
}



void game::addObject(Objet & o)
{
    items->push_back(o);
    scenery->addItem(&o);
    o.setFlag(QGraphicsItem::ItemIsFocusable);
    o.setFocus();
    qDebug()<<"objet "<<o.getName()<<" ajouté";
}

void game::addSmoke(Smoke *s)
{
    smokey_items->push_back(s);
    scenery->addItem(s);
    s->setFlag(QGraphicsItem::ItemIsFocusable);
    s->setFocus();
    qDebug()<<"smoke"<<s->getName()<<" ajouté";
}


void game::isGameOver()
{
        qDebug()<<"is game over?"<< " all i wonder";
    for (std::vector<Smoke*>::iterator it=smokey_items->begin(); it !=smokey_items->end(); ++it)
    {
                qDebug()<< "testing "<<(*it)->getName();
        if ((*it)->x() < 400 || (*it)->y() < 300) // si un des objets fumée du jeu n'est pas dans le sac
        {
            qDebug()<<" pos de l'objet "<< (*it)->x() << "et " << (*it)->y();
            return; //on sort de la fonction
        }
    }

    //test en selcetionnant juste les objets dans la scene


    // une fois qu'on est arrivé là , tous les objets smoke sont dans le sac
    //c'est la fin du jeu

    mb->show();
}
void game::testGame()
{
       QTimer * timer = new QTimer();
       QObject::connect(timer, SIGNAL(timeout()), this, SLOT(isGameOver()));
       timer->start(500);
}


/*void game::drawBackground ( QPainter * painter, const QRectF & rect )
{
    QRectF target(0.0, 0.0, 800.0, 494.0);
    QRectF source(0.0, 0.0, 400.0, 247.0);
    QPixmap pixmap(":/images/images/usine.png");
    painter->drawPixmap(target, pixmap, source);
  QGraphicsScene::drawBackground(painter,rect);
}*/
