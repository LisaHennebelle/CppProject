#pragma once
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include<QString>

class Objet:public QGraphicsRectItem, QObject{
    QString name;
    int flag=0; // determine si l'objet s'est fait cliqué dessus
public:
    // constructeurs
    Objet();
    Objet(QString nom);
    Objet(const Objet &o);

    void setName(QString nom);
    QString getName();
    int getFlag();


    void keyPressEvent(QKeyEvent* event);
   // void tilePressEvent(QKeyEvent *event, int i = 0);
   //~Objet();
    bool operator == (const Objet& s) const { return name == s.name; }
    const Objet operator =(const Objet& s) const { return s; }
};
