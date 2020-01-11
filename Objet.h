#ifndef OBJET_H
#define OBJET_H


#include <QGraphicsRectItem>
#include <QMouseEvent>
#include<QString>

class Objet:public QGraphicsRectItem{
    QString name;
public:
    // constructeurs
    Objet();
    Objet(QString nom);
    Objet(const Objet &o);

    void setName(QString nom);
    QString getName();
    int MouseEvent(QMouseEvent* event); // retourne 1 si l'utilisateur a cliqué sur l'objet
    void keyPressEvent(QKeyEvent* event);
   // void tilePressEvent(QKeyEvent *event, int i = 0);
   //~Objet();
    bool operator == (const Objet& s) const { return name == s.name; }
    const Objet operator =(const Objet& s) const { return s; }
};

#endif // OBJET_H
