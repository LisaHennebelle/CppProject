#include "code.h"
#include<QDebug>


Code::Code()
{
    locked = 1;
    this->setName("unnamed");
    assObj.setName("unnamed");
}

Code::Code(std::string nom)
{
    locked = 1;
    this->setName(nom);
    assObj.setName("unnamed");
}

Code::Code(std::string nom ,Objet o)
{
  locked = 1;
  this->setName(nom);
  assObj = o; //pb lies au copy constructor
  i = new indice(o, "not set");

}

// set attributs
void Code::associerNom(std::string nom)
{
    this->setName(nom);
}

void Code::associerObj(Objet o)
{
    assObj = o;
    i.addObjet(o);
}

// unlocker le code avec un objet
void Code::unlockWith(Objet o)
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
