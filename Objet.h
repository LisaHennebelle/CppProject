#ifndef OBJET_H
#define OBJET_H
#include <QGraphicsRectItem>
#include <QMouseEvent>

class Objet:public QGraphicsRectItem{
public:
    std::string name;
    Objet();
    Objet(std::string mot);
    Objet(const Objet &o);
    int MouseEvent(QMouseEvent *event); // retourne 1 si l'utilisateur a cliqué sur l'objet
    void keyPressEvent(QKeyEvent * event);
   // void tilePressEvent(QKeyEvent *event, int i = 0);
   ~Objet();
    bool operator == (const Objet& s) const { return name == s.name; }
};

#endif // OBJET_H
