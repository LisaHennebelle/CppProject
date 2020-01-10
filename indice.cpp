#include "indice.h"

// constructeurs
indice::indice(std::string message)
{
    text = message;
    relObj.setName("unnamed");
}

indice::indice(Objet o)
{
    relObj = o;
    text = "not set";
}

indice::indice(Objet o, std::string message)
{
    relObj = o;
    text = message;
}

indice::indice(const indice &i)
{
    this->relObj =i.relObj;
    this->text = i.text;
}
//setter

void indice::setText(std::string message)
{
    text = message;
}

void indice::addObjet(Objet o)
{
    relObj = o;
}

void indice::show()
{
    //this->setText("The document has been modified.");
    this->exec();
}


