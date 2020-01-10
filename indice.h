#ifndef INDICE_H
#define INDICE_H
#include <QGraphicsSimpleTextItem>
#include "Objet.h"

// indice est une classe presque purement graphique
// elle permet d'afficher un indice lié à un objet
class indice: public QGraphicsSimpleTextItem
{
    std::string text;
    Objet relObj; //related objet
public:
    //indice();
    indice (std::string message);
    void setText(std::string message);
    void addObjet(Objet o);// permet de savoir sur quel Objet porte l'indice pour pouvoir l'afficher
    void show();
};

#endif // INDICE_H
