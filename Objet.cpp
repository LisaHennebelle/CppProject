#include "Objet.h"
#include <QGraphicsRectItem>
#include<QDebug>
#include<QKeyEvent>
#include<QGraphicsScene>
void Objet::keyPressEvent(QKeyEvent *event)
{
    static int i =0;
    qDebug()<< "Vous venez de selectionner l'image";
    if( event->key() == Qt::Key_Left ){
        setPos(x()-10,y());

        if(event->key() == Qt::Key_0)
        {
           qDebug()<< "code saisi";
           i = 1;
           return keyPressEvent(event);}
        else if(event->key() == Qt::Key_1 && i == 1)
        {
           i++;
           //return keyPressEvent(event);
        }

       else if(event->key() == Qt::Key_2 && i == 2)
       {
           i++;
           //return keyPressEvent(event);
        }

        else if(event->key() == Qt::Key_3 && i == 3)
        {
           //return keyPressEvent(event);
        }
        else if (i == 4) {
             qDebug()<< "le code a été coreectement saisi";
            return;}
    }
}
Objet::~Objet()
{
     delete this; //il ne le reconnait pas
}

// test de code numerique
/*void Objet::tilePressEvent(QKeyEvent *event, int i)
    {


     if(event->key() == Qt::Key_0)
     {
        qDebug()<< "code saisi";
        static int i = 1;
        return keyPressEvent(event);}
     else if(event->key() == Qt::Key_1 && i == 1)
     {
        i++;
        //return keyPressEvent(event);}

    else if(event->key() == Qt::Key_2 && i == 2)
    {
        i++;
        //return keyPressEvent(event);}

     else if(event->key() == Qt::Key_3 && i == 3)
     {
        //return keyPressEvent(event);}
     else if (i == 4) {
          qDebug()<< "le code a été coreectement saisi";
         return;}
    }*/
