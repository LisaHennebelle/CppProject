#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "Objet.h"
#include "Smoke.h"
#include "background.h"
#include "list"
#include <QList>
#include "QGraphicsScene"
#define NUM_OBJET 2
#define NUM_SMOKE 3

class game : public QObject{
    Q_OBJECT
    QMessageBox* mb = new QMessageBox;
    std::list<Objet> *items = new std::list<Objet> ();
    std::vector<Smoke *> *smokey_items = new std::vector<Smoke*>() ;
    int over;

public:
     QGraphicsScene *scenery = new QGraphicsScene;
     // vue publique
    game();
    ~game();
    void test(Smoke s);
    void paintEvent(QPaintEvent *pe);
    void addObject(Objet & o); // pour que les lock soient changés
    void addSmoke(Smoke *s);
    void testGame();
    void drawBackground ( QPainter * painter, const QRectF & rect );

public slots:
    void isGameOver();
};

#endif // GAME_H
