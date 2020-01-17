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
    //etRect(0,0,800,100);//le sac peut contenir 8 objet de taille 100x100
    setPixmap(QPixmap(":/images/images/sac.png"));
    setPos(x()+400, y()+300);//il est represente en bas à droite de l'appli
    nb_items = 0;
    items = list<Objet>();
    qDebug()<<"Mes positions sont " << x() <<" et " << y();
}

void Sac::addObject(Objet &r)
{
    qDebug()<<"addObjet";
    if (r.getFlag() == 1){
        if (nb_items >= MAX) //si le sac est rempli on cree une erreur
        {
            qDebug() << "Trop d'objets, on ne peut pas en ajouter d'autres";
            return;
        }
        nb_items ++;
        items.push_back(r);
         this->isObscuredBy(&r);
        qDebug()<<"objet ajouté :"<<r.getName();

        r.setPos(x()+100*nb_items,y());//on change la position de l'objet pour le mettre dans le sac
    }
}
void Sac::rmObject(Objet &r)
{
    for (list<Objet>::iterator it=items.begin(); it != items.end(); ++it)
    {
        if (*it == r) //si la liste des items contient r
        {
            items.remove(*it);// on retire l'objet de la liste
             nb_items --; //on decremente le nombre d'items
        }
    }

}


