#include "Objet.h"
#include <QGraphicsRectItem>
#include<QDebug>
#include <QTimer>
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

int Objet::getFlag()
{
    return flag;
}

// comportement
int Objet::MouseEvent(QMouseEvent *event)
{
   /* QTimer* qtim = new QTimer(this);// creer un timer pour faire que la fonction soit appelee periodiquement
    connect(qtim, SIGNAL(timeout()), this, SLOT(move()));
    qtim->start(50);*/
    int i = 0;
    if (event->button() == Qt::LeftButton && i == 0)
    {
        i ++;
        if ( event->globalX() > this->x() && event->globalY() > this-> y()){
            qDebug()<<"flag à 1 de "<<this-> getName();
        flag = 1;
        return 1;
        }
    }
    qDebug()<<"flag à 0 de "<<this-> getName();
    flag = 0;
    return 0;
}
void Objet::keyPressEvent(QKeyEvent *event)
{
    static int i =0;
    static int j = 0;

    if( event->key() == Qt::Key_Left ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x()-10,y());}

    if( event->key() == Qt::Key_Right){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x()+10,y());}
    if( event->key() == Qt::Key_Up ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x(),y()-10);}
    if( event->key() == Qt::Key_Down ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x(),y()+10);}

    if (event->key() == Qt::Key_Enter)
    {
            if(j == 0) //premiere fois que l'uitlisateur appuie sur entree en ayant selectionné l'objet
            {
                j ++;
                if ( this->x() < 500 && this-> y() < 300){
                    qDebug()<<"flag à 1 de "<<this-> getName();
                flag = 1;
                }

            else
            {
                qDebug()<<"flag à 0 de "<<this-> getName();
                flag = 0;
            }
            }


     }

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

