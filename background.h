#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QWidget>
#include <QtGui>
#include <QGraphicsRectItem>
#include <QWidget>


class background: public QWidget, public QGraphicsRectItem{
   protected:
    int  ok = 0;
public:
    background();
void paintEvent(QPaintEvent *pe);
signals:

public slots:

};

#endif // BACKGROUND_H
