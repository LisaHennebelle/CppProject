#include "indice.h"
#include <string>
#include <iostream>

// constructeurs
indice::indice(QString message)
{
    this-> QMessageBox::setText(message);
    text = message;
    //relObj->setName("unnamed");
}


indice::indice(const indice &i)
{
    //this->relObj =i.relObj;
    this->text = i.text;
}
//setter

void indice::setText(QString message)
{
   // text = message;
    this->QMessageBox::setText(message);
    std::cout<<"on est dans setText()"<<std::endl;
    this-> exec();
}


// getter
/*
Objet indice::getObjet()
{
    return *relObj;
}

void indice::addObjet(Objet* o)
{
    relObj = o;
}*/

void indice::show()
{
    //this->QMessageBox::setText("The document has been modified.");
    this->exec();
}


