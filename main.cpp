
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
    Sac * sac = new Sac();
    rect->setRect(0,0,100,100);
    sac->setRect(0,0,800,800);

    scene->addItem(rect);
    scene-> addItem(sac);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();




    return a.exec();
}
