#include "code.h"
#include "indice.h"
#include<QDebug>


Code::Code()
{
    locked = 1;
    this->setName("unnamed");
    assObj->setName("unnamed");

}

Code::Code(QString nom)
{
    locked = 1;
    this->setName(nom);
    assObj->setName("unnamed");
}

Code::Code(QString nom ,Objet* o)
{
  locked = 1;
  this->setName(nom);
  assObj = o; //pb lies au copy constructor
  i->addObjet(o);

}

// set attributs
void Code::associerNom(QString nom)
{
    this->setName(nom);
}

void Code::associerObj(Objet* o)
{
    assObj = o;
    i->addObjet(o);
}


void Code::associerIndice(indice* in)
{
    i = in;
    if((i->getObjet()).getName()== "not set")
        i->addObjet(assObj);
}

// unlocker le code avec un objet
// a utiliser si l'utilisateur selectionne un objet puis le code
void Code::unlockWith(Objet* o)
{
    if (assObj == o) // si l'objet selectionne etait bien celui associé au code
    {
        locked = 0;
       qDebug() << "Bien joue vous avez debloqué l'objet ";
        //il faudra generer une fenetre ou un lien de conversation
       return;
    }
    qDebug() << "Try again!"; // si l'objet selectionné n'était pas le bon

}

void Code::showIndice()
{
    i->show();
    // decrementer le timer du jeu?
}
