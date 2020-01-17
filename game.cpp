#include "game.h"
#include <QTimer>
#include <QDebug>
#include "Objet.h"
#include <list>

game::game()
{
    // taille des listes imposée
    items->resize(NUM_OBJET);
    items->resize(NUM_SMOKE);

    // création des objets
    QString a = 0;
    int  i = 0;
    for (i = 0 ; i <NUM_OBJET ; i++) // remplissage de la liste des objets
    {
        QString name = "objet_ "+ a ;
        a = a+1;
        Objet *o = new Objet(name);
        items->push_back(*o);
        qDebug() << "ajout de l'objet : "<< o->getName();
    }
    over = 0;


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
    for (std::list<Smoke>::iterator it=smokey_items->begin(); it !=smokey_items->end(); ++it)
    {
    smokey_items -> erase(it);
    }
}

void game::addObject(Objet & o)
{
    items->push_back(o);
    qDebug()<<"objet "<<o.getName()<<" ajouté";
}

void game::addSmoke(Smoke & s)
{
    smokey_items->push_back(s);
    qDebug()<<"smoke"<<s.getName()<<" ajouté";
}

void game::isGameOver()
{
        qDebug()<<"is game over?"<< " all i wonder";
            for (std::list<Smoke>::iterator it=smokey_items->begin(); it !=smokey_items->end(); ++it)
    {
                qDebug()<< "testing "<<(*it).getName();
        if ((*it).x() < 400 || (*it).y() < 300) // si un des objets fumée du jeu n'est pas dans le sac
        {
            qDebug()<<" pos de l'objet "<< (*it).x() << "et " << (*it).y();
            return; //on sort de la fonction
        }
    }
    qDebug() << "game over but game doesn't know";
    QMessageBox *mb = new QMessageBox; // une fois qu'on est arrivé là , tous les objets smoke sont dans le sac
    //c'est la fin du jeu
    mb ->setText("GAME OVER");
    mb->show();
}
void game::testGame()
{
       QTimer * timer = new QTimer();
       connect(timer, SIGNAL(timeout()), this, SLOT(isGameOver()));
       timer->start(500);
}
