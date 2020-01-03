#ifndef SAC_H
#define SAC_H

#include <QList>
#include <QObject>
#include "Objet.h"
#include <QGraphicsRectItem>



class Sac: public QGraphicsRectItem,public QObject
{    
    QList <Objet> items;
    int nb_items;
public:
    Sac();
    void addObject(Objet r);
    void rmObject(const Objet &r);
};

#endif // SAC_H
