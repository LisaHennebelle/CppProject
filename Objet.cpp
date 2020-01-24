#include "Objet.h"
#include <QGraphicsRectItem>
#include<QDebug>
#include <QTimer>
#include<QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsColorizeEffect>
#include <QMessageBox>
#include<QGraphicsScene>
#include<string>
#define SACX 800
#define SACY 500

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
      QMessageBox * qm = new QMessageBox();
    if( event->key() == Qt::Key_Left ){


        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x()-10,y());
        if ( this->x() > SACX && this->y() > SACY )
        {
            this->setActive(false);
            qm->setText("Ceci n'est pas un objet en rapport avec la fumée, essayez encore");
            qm->show();
        }
    }
    if( event->key() == Qt::Key_Right){

        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x()+10,y());
        if ( this->x() > SACX && this->y() > SACY )
        {
            this->setActive(false);
            qm->setText("Ceci n'est pas un objet en rapport avec la fumée, essayez encore");
            qm->show();
        }

    }
    if( event->key() == Qt::Key_Up ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x(),y()-10);
        if ( this->x() > SACX && this->y() > SACY )
        {
            this->setActive(false);
            qm->setText("Ceci n'est pas un objet en rapport avec la fumée, essayez encore");
            qm->show();
        }
    }
    if( event->key() == Qt::Key_Down ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x(),y()+10);
        if ( this->x() > SACX && this->y() > SACY )
        {
            this->setActive(false);
            qm->setText("Ceci n'est pas un objet en rapport avec la fumée, essayez encore");
            qm->show();
        }
    }


    if(event->key() == Qt::Key_0)
        {
            qm ->setText("Mauvais bouton ...");
            qm ->show();
        }
         if(event->key() == Qt::Key_1 )
        {
            qm ->setText("Essayez I ");
            qm ->show();
        }

         if(event->key() == Qt::Key_V)
        {
             QGraphicsColorizeEffect * qc = new QGraphicsColorizeEffect();
             QColor *dark = new QColor();
             dark ->setGreenF(0.1);
             qc->setColor(*dark);
            setGraphicsEffect(qc);
        }

         if(event->key() == Qt::Key_R)
        {
             QGraphicsColorizeEffect * qc = new QGraphicsColorizeEffect();
             QColor *dark = new QColor();
             dark ->setRedF(0.1);
             qc->setColor(*dark);
            setGraphicsEffect(qc);
        }
         if(event->key() == Qt::Key_B)
        {
             QGraphicsColorizeEffect * qc = new QGraphicsColorizeEffect();
             QColor *dark = new QColor();
             dark ->setBlueF(0.1);
             qc->setColor(*dark);
            setGraphicsEffect(qc);
        }


         if(event->key() == Qt::Key_I )
        {
            qm ->setText("Le but est simple :\n\
                         Retrouvez les objets relatifs à la fumée et mettez les dans le sac avec les flèches de votre clavier!\
                         \n\n N'hésitez pas à tester d'autres touches, vous aurez peut-être des surprises ... ");
            qm ->show();
        }


        if(event->key() == Qt::Key_2 || event->key() == Qt::Key_3  || event->key() == Qt::Key_4  || event->key() == Qt::Key_5 || event->key() == Qt::Key_6 || event->key() == Qt::Key_7 || event->key() == Qt::Key_8 || event->key() == Qt::Key_9 )
       {
            qm->setText("Ceci est inutile... ");
            qm->show();

        }



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


