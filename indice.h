#ifndef INDICE_H
#define INDICE_H
#include <QMessageBox>
#include "Objet.h"
#include<QString>

// indice est une classe presque purement graphique
// elle permet d'afficher un indice lié à un objet
class indice: public QMessageBox
{
    QString text;
    Objet* relObj = new Objet("unnamed"); //related objet
public:
    //constructeurs
    indice (QString message);
    indice (Objet* o);
    indice (Objet* o, QString message);
    indice(const indice &i);

    void setText(QString message);
    Objet getObjet();
    void addObjet(Objet* o);// permet de savoir sur quel Objet porte l'indice pour pouvoir l'afficher
    void show();

    const indice operator =(const indice& i) const { return i; }
};

#endif // INDICE_H
