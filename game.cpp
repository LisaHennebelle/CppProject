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

    smokey_items->resize(NUM_SMOKE);
    mb->setText("GAME OVER");

    over = 0;// over initialisé à 0

    // ajout de la liste des objet et ajout à la scene
    addItems();
    // creation de la variable sac
    Sac * sac = new Sac();
    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();
    scenery ->addItem(sac);
    //ajout de la liste des smokey items et ajout à la scene
    addSmokeyItems();

    qDebug("game created with success");
}
game::~game()
{
    qDebug()<<"game finished";
    //eliminitaion de tous les elements de la liste items
    for (std::list<Objet>::iterator it_o=items->begin(); it_o !=items->end(); it_o++)
    {
        items -> erase(it_o);
    }
    // elimination de tous les elements de la liste smokey_items
    for (std::list<Smoke*>::iterator it=smokey_items->begin(); it !=smokey_items->end(); it++)
    {
    smokey_items -> erase(it);
    }
}



void game::addObject(Objet & o)
{
    o.addPixmapnew();
    items->push_back(o);
    scenery->addItem(&o);
    o.setFlag(QGraphicsItem::ItemIsFocusable);
    o.setFocus();
    qDebug()<<"objet "<<o.getName()<<" ajouté";
}

void game::addSmoke(Smoke *s)
{
    s->addPixmapnew();
    smokey_items->push_back(s);
    scenery->addItem(s);
    s->setFlag(QGraphicsItem::ItemIsFocusable);
    s->setFocus();
    qDebug()<<"smoke"<<s->getName()<<" ajouté";
}

void game::addItems()
{
    items->resize(NUM_OBJET);
    // creation du background bg
    Objet *bg = new Objet("usine");
    bg->setPos(bg->x(), bg->y());
    this->addObject(*bg);


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

    }

}

void game::addSmokeyItems()
{
    Smoke * loco = new Smoke("loco");
    addSmoke(loco); //ajout a la scene et creation du pixmap
    Smoke * cheminee = new Smoke("cheminee");
    addSmoke(cheminee);//ajout a la scene et creation du pixmap
    Smoke * cigarette = new Smoke("cigarette");
    addSmoke(cigarette);//ajout a la scene et creation du pixmap
    // set location

    loco->setPos(loco->x()+10, loco->y()+20);
    cheminee->setPos(cheminee->x()+200, cheminee->y()+300);
    cigarette->setPos(cigarette->x()+400, cigarette->y());

    // ajout des indices
    indice *indice_cigarette = new indice("Ceci est une pipe");
    indice *deuxieme = new indice("Ceci est une flamme");
    indice *troisieme = new indice("Ceci est un smokey butt");
    cigarette->associerIndice(indice_cigarette);
    loco->associerIndice(deuxieme);
    cheminee-> associerIndice(troisieme);
}

void game::isGameOver()
{
        qDebug()<<"is game over?"<< " all i wonder";
    for (std::list<Smoke*>::iterator it=smokey_items->begin(); it !=smokey_items->end(); ++it)
    {
        qDebug()<< "testing "<<(*it)->getName();
        if ((*it)->x() < 1200 || (*it)->y() < 800) // si un des objets fumée du jeu n'est pas dans le sac
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


