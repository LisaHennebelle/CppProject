#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>

class MyRect:public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
   // void tilePressEvent(QKeyEvent *event, int i = 0);
   ~MyRect();
};

#endif // MYRECT_H
