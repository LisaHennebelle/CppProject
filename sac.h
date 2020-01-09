#ifndef SAC_H
#define SAC_H

#include <list>
#include <QObject>
#include "Objet.h"
#include <QGraphicsRectItem>



class Sac: public QGraphicsRectItem//,public QObject
{    
    std::list<Objet> items;
    int nb_items;
public:
    Sac();
    void addObject(Objet r);
    void rmObject( Objet r);
};

#endif // SAC_H
