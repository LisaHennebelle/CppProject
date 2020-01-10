#ifndef INDICE_H
#define INDICE_H
#include <QMessageBox>
#include "Objet.h"

// indice est une classe presque purement graphique
// elle permet d'afficher un indice lié à un objet
class indice: public QMessageBox
{
    std::string text;
    Objet relObj; //related objet
public:
    //constructeurs
    indice (std::string message);
    indice (Objet o);
    indice (Objet o, std::string message);
    indice(const indice &i);

    void setText(std::string message);
    void addObjet(Objet o);// permet de savoir sur quel Objet porte l'indice pour pouvoir l'afficher
    void show();
};

#endif // INDICE_H
