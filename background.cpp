#include "background.h"
#include <QDebug>

background::background()
{
    setActive(true);
    setMinimumHeight(500);
    setMaximumWidth(400);
    QGraphicsRectItem::setVisible(true);
    setBackgroundRole(QPalette::Background);
    ok = 1;
    qDebug() << "ok = "<< ok;
}


void background::paintEvent(QPaintEvent *pe){
// setting background
QPixmap pixmap;
pixmap.load(":/images/images/usine.png");
QPainter paint(this);
int widWidth = 400;
int widHeight = 400;
pixmap = pixmap.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
paint.drawPixmap(0, 0, pixmap);
QWidget::paintEvent(pe);
}
