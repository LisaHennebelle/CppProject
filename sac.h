#pragma once
#include <list>
#include <QObject>
#include "Objet.h"
#include <QGraphicsPixmapItem>
#include <QString>



class Sac: public QGraphicsPixmapItem//,public QObject
{    
    std::list<Objet> items;
    int nb_items;
public:
    Sac();
    void addObject(Objet r);
    void rmObject( Objet r);
};


