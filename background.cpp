#include "background.h"
#include <QDebug>

background::background(int version )
{
    QString type;
    setActive(true);
    this->setPos(this->x(), this->y());
    if (version == 0)
    {type = ":/images/images/chambre.png";}
    else if (version == 1)
    {type = ":/images/images/Dark.png";}
     QPixmap *qp  = new QPixmap(type);
    this->setPixmap(*qp);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    qDebug() << "ok = "<< ok;
}


