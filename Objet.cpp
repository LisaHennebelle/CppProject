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
    //this->setRect(o.rect());
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
void Objet::addPixmap(QPixmap *qp)
{
    setPixmap(*qp);
}

void Objet::addPixmapnew()
{
    QString *pixmapname = new QString();
   *pixmapname = (":/images/images/" + this->getName() + ".png");
    qDebug() << *pixmapname;
    QPixmap *p = new QPixmap(*pixmapname);
    qDebug() << "pixmap créé";
    setPixmap(*p);
}
/*Objet::~Objet()
{
     delete this; //il ne le reconnait pas
}*/

