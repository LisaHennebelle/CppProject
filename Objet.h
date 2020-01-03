#ifndef OBJET_H
#define OBJET_H
#include <QGraphicsRectItem>

class Objet:public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
   // void tilePressEvent(QKeyEvent *event, int i = 0);
   ~Objet();
};

#endif // OBJET_H
