#ifndef CODE_H
#define CODE_H
#include "Objet.h"
#include "indice.h"
#include<QString>

class Smoke: public Objet// objet en rapport avec la flamme
{
    int locked=0;
    //Objet* assObj = new Objet("unnamed"); // objet associe à la résolution du code
    indice* i = (new indice("not set"));
public:
    Smoke();
    Smoke(QString nom);
    int getLock();
    void associerNom(QString nom);
    int MouseEvent(QMouseEvent* event); // retourne 1 si l'utilisateur a cliqué sur l'objet
    void keyPressEvent(QKeyEvent* event);
     // void associerObj(Objet* o);
    void associerIndice(indice* in);
    void showIndice(); // afficher une fenetre contenant un indice
    //void setUnlockedImage(); //pour l'affichage graphique, une fois que l'objet est ouvert
    //void unlockWith(Objet* o);

};

#endif // CODE_H
