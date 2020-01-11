#ifndef CODE_H
#define CODE_H
#include "Objet.h"
#include "indice.h"
#include<QString>

class Code: public Objet
{
    int locked;
    Objet* assObj = new Objet("unnamed"); // objet associe à la résolution du code
    indice* i = (new indice("not set"));
public:
    Code();
    Code(QString nom);
    Code(QString nom, Objet* o);
    void associerNom(QString nom);
    void associerObj(Objet* o);
    void associerIndice(indice* in);
    void showIndice(); // afficher une fenetre contenant un indice
    //void setUnlockedImage(); //pour l'affichage graphique, une fois que l'objet est ouvert
    void unlockWith(Objet* o);

};

#endif // CODE_H
