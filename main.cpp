
#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include "sac.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene= new QGraphicsScene();

    MyRect * rect = new MyRect();
    MyRect * rect2 = new MyRect();


    Sac * sac = new Sac();
    rect->setRect(0,0,100,100);
    rect->setRect(-10,-10,100,100);
    sac->setRect(10,10,800,800);
    //sac->addObject(*rect);

    scene->addItem(rect);
    scene->addItem(rect2);
    scene-> addItem(sac);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    rect2->setFlag(QGraphicsItem::ItemIsFocusable);
    rect2->setFocus();

    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();



    return a.exec();
}
