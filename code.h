#ifndef CODE_H
#define CODE_H
#include "Objet.h"
#include "indice.h"

class Code: public Objet
{
    int locked;
    Objet assObj; // objet associe à la résolution du code
    indice i = (*new indice("not set"));
public:
    Code();
    Code(std::string nom);
    Code(std::string nom, Objet o);
    void associerNom(std::string nom);
    void associerObj(Objet o);
    void associerIndice(indice i);
    void showIndice(); // afficher une fenetre contenant un indice
    //void setUnlockedImage(); //pour l'affichage graphique, une fois que l'objet est ouvert
    void unlockWith(Objet o);

};

#endif // CODE_H
