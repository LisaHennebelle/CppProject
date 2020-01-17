#include "Smoke.h"
#include "indice.h"
#include<QDebug>


Smoke::Smoke()
{
    this->setName("unnamed");
}

Smoke::Smoke(QString nom)
{

    this->setName(nom);
}

int Smoke::getLock()
{
    return locked;
}


// set attributs
void Smoke::associerNom(QString nom)
{
    this->setName(nom);
}


void Smoke::associerIndice(indice* in)
{
    i = in;
}

// unlocker le code avec un objet
// a utiliser si l'utilisateur selectionne un objet puis le code

void Smoke::showIndice()
{
    i->show();
    // decrementer le timer du jeu?
}

int Smoke::MouseEvent(QMouseEvent *event)
{
   /* QTimer* qtim = new QTimer(this);// creer un timer pour faire que la fonction soit appelee periodiquement
    connect(qtim, SIGNAL(timeout()), this, SLOT(move()));
    qtim->start(50);*/
    if (event->button() == Qt::LeftButton)
    {
        qDebug()<<"flag à 1 de "<<this-> getName();
        if ( event->globalX() > this->x() && event->globalY() > this-> y()){
            qDebug()<<"flag à 1 de "<<this-> getName();

        return 1;
        }
    }
    qDebug()<<"flag à 0 de "<<this-> getName();
   return 0;
}

void Smoke::keyPressEvent(QKeyEvent * event)
{
    if( event->key() == Qt::Key_Left )
    {
        qDebug()<< "left " <<this->getName();
        setPos(x()-10,y());
        if( x() > 400 && y() > 300 )
        {
            qDebug() << "je suis dans le sac";
            locked =1;
        }
    }

    if( event->key() == Qt::Key_Right){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x()+10,y());
        if( x() > 400 && y() > 300 )
        {
            qDebug() << "je suis dans le sac";
             locked =1;
        }}
    if( event->key() == Qt::Key_Up ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x(),y()-10);
        if( x() > 400 && y() > 300 )
        {
            qDebug() << "je suis dans le sac";
             locked =1;
        }}
    if( event->key() == Qt::Key_Down ){
        qDebug()<< "Vous venez de selectionner " <<this->getName();
        setPos(x(),y()+10);
        if( x() > 400 && y() > 300 )
        {
            qDebug() << "je suis dans le sac";
             locked =1;
        }}


    if (event->key() == Qt::Key_Return)
    {
        qDebug()<<"entree ";
        i->show();
        //flag = 1;
     }

}
