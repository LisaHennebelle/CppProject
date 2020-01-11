#include "Objet.h"
#include <QGraphicsRectItem>
#include<QDebug>
#include<QKeyEvent>
#include <QMouseEvent>
#include<QGraphicsScene>
#include<string>

// constructeurs
Objet::Objet()
{
    name = "unnamed";
}

Objet::Objet(QString nom)
{
    name = nom;
}

Objet::Objet(const Objet &o)//:QGraphicsRectItem(o)
{
    this->setRect(o.rect());
    this->name = o.name;
}


// getter et setter
void Objet::setName(QString nom)
{
    name = nom;
}

QString Objet::getName()
{
    return name;
}

// comportement
int Objet::MouseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        return 1;
    }
    return 0;
}
void Objet::keyPressEvent(QKeyEvent *event)
{
    static int i =0;
    qDebug()<< "Vous venez de selectionner l'image";
    if( event->key() == Qt::Key_Left ){
        setPos(x()-10,y());}

        if(event->key() == Qt::Key_0)
        {
           qDebug()<< "code saisi";
           i = 1;
           //return keyPressEvent(event);
        }
         if(event->key() == Qt::Key_1 && i == 1)
        {
           i++;
           //return keyPressEvent(event);
        }

        if(event->key() == Qt::Key_2 && i == 2)
       {
           i++;
           //return keyPressEvent(event);
        }

         if(event->key() == Qt::Key_3 && i == 3)
        {
           //return keyPressEvent(event);
        }
        if (i == 4) {
             qDebug()<< "le code a été correctement saisi";
            return;}
    }

/*Objet::~Objet()
{
     delete this; //il ne le reconnait pas
}*/

