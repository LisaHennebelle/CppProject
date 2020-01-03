#include "MyRect.h"
#include <QGraphicsRectItem>
#include<QDebug>
#include<QKeyEvent>
void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< "Vous venez de selectionner l'image";
    if( event->key() == Qt::Key_Left ){
        setPos(x()-10,y());
    }
}

/*MyRect::~MyRect()
{
    ~QGraphicsRectItem(); //il ne le reconnait pas
}*/

// test de code numerique
/*void MyRect::tilePressEvent(QKeyEvent *event, int i)
    {
    qDebug()<< "code saisi";

     if(event->key() == Qt::Key_0)
     {

        return tilePressEvent(event,1);}
     else if(event->key() == Qt::Key_1 && i == 1)
     {
        return tilePressEvent(event,2);}

    else if(event->key() == Qt::Key_2 && i == 2)
    {
        return tilePressEvent(event,3);}

     else if(event->key() == Qt::Key_3 && i == 3)
     {
        return tilePressEvent(event,4);}
     else if (i == 4) {
          qDebug()<< "le code a été coreectement saisi";
         return;}
    }*/
