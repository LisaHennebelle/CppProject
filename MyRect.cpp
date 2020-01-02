#include "MyRect.h"
#include<QDebug>
#include<QKeyEvent>
void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "Vous venez de selectionner l'image";
    if( event->key() == Qt::Key_Left ){
        setPos(x()-10,y());
    }
}
