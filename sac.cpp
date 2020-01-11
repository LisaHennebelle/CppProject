#include "sac.h"
#include <list>
#include <iterator>
#include<QDebug>
#include <QGraphicsRectItem>

//#include "Objet.h"
#define MAX 8
using namespace std;

Sac::Sac()
{
    setRect(0,0,800,100);//le sac peut contenir 8 objet de taille 100x100
    setPos(x()+500, y()+500);//il est represente en bas à droite de l'appli
    nb_items = 0;
    items = list<Objet>();
}

void Sac::addObject(Objet r)
{
    nb_items ++;
    if (nb_items >= MAX) //si le sac est rempli on cree une erreur
    {
        qDebug() << "Trop d'objets, on ne peut pas en ajouter d'autres";
        return;
    }

    items.push_back(r);
    r.setPos(x()+100*nb_items,y());//on change la position de l'objet pour le mettre dans le sac
}

void Sac::rmObject(Objet r)
{
    for (list<Objet>::iterator it=items.begin(); it != items.end(); ++it)
    {
        if (*it == r)
        {
            items.remove(*it);// on retire l'objet de la liste
             nb_items --; //on decremente le nombre d'items
        }
    }

   //if (items.contains(r)) //si le sac contient l'objet
       //on retire l'objet
       //items.takeAt(items.indexOf(r));//index pose pb

}


