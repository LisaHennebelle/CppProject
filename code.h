#ifndef CODE_H
#define CODE_H
#include "Objet.h"

class Code: public Objet
{
    int locked;
    Objet assObj; // objet associe à la résolution du code
    //Indice i; // a mettre une fois qu'on aura cree la classe indice
public:
    Code();
    Code(std::string nom);
    Code(std::string nom, Objet o);
    void associerNom(std::string nom);
    void associerObj(Objet o);
    //void showIndice(); // afficher une fenetre contenant un indice
    // void setUnlockedImage(); //pour l'affichage graphique
    void unlockWith(Objet o);

};

#endif // CODE_H
