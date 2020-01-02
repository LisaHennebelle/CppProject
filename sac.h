#ifndef SAC_H
#define SAC_H
//#include <list>
#include "MyRect.h"
#include <QGraphicsRectItem>



class Sac: public QGraphicsRectItem
{    
    std::list <MyRect> items;
    int nb_items;
public:
    Sac();
    void addObject(MyRect r);
    void rmObject(MyRect r);
};

#endif // SAC_H
