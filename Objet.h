#ifndef OBJET_H
#define OBJET_H
#include <QGraphicsRectItem>
#include <QMouseEvent>

class Objet:public QGraphicsRectItem{
    std::string name;
public:
    // constructeurs
    Objet();
    Objet(std::string nom);
    Objet(const Objet &o);

    void setName(std::string nom);
    std::string getName();
    int MouseEvent(QMouseEvent *event); // retourne 1 si l'utilisateur a cliqué sur l'objet
    void keyPressEvent(QKeyEvent * event);
   // void tilePressEvent(QKeyEvent *event, int i = 0);
   ~Objet();
    bool operator == (const Objet& s) const { return name == s.name; }
    const Objet operator =(const Objet& s) const { return s; }
};

#endif // OBJET_H
