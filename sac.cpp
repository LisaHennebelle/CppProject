#include "sac.h"
#include <QList>
#include <iterator>
#include<QDebug>
#include <QGraphicsRectItem>

//#include "MyRect.h"
#define MAX 8

Sac::Sac()
{
    nb_items = 0;
    items = QList<MyRect>();
}

void Sac::addObject(MyRect r)
{
    nb_items ++;
    if (nb_items >= MAX)
    {
        qDebug() << "Trop d'objets, on ne peut pas en ajouter d'autres";
        return;
    }
    //std::list <MyRect>::iterator ite;
    items.push_back(r);
    r.setPos(x()-100,y());
}

void Sac::rmObject(MyRect r)
{
   if (items.contains(r))
   {
       items.removeAt(items.indexOf(r));
       nb_items --;
   }
}


