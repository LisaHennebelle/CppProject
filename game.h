#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "Objet.h"
#include "Smoke.h"
#include "background.h"
#include "list"
#include <QList>
#include <QButtonGroup>
#include <QPushButton>
#include "QGraphicsScene"
#define NUM_OBJET 2
#define NUM_SMOKE 3
#define LITE 0
#define DARK 1

class game : public QObject{
    Q_OBJECT
    QMessageBox* mb = new QMessageBox;// pour la fin du jeu
    QString *score;
    //on fait deux listes d'items en fonction de la version de jeu qu'on désire
    // version lite
    QList<Objet*> *itemsLite = new QList<Objet*> ();
    QList<Smoke *> *smokey_itemsLite = new QList<Smoke*>() ;
    //version dark
    QList<Objet*> *itemsDark = new QList<Objet*> ();
    QList<Smoke *> *smokey_itemsDark = new QList<Smoke*>() ;

    int gameVersion = 0;
    QTimer * timer = new QTimer();
    QTimer *timerJeu = new QTimer();

public:

    int over = 0;// on determine si la partie est terminee grace à over
     QGraphicsScene *scenery = new QGraphicsScene;
     // vue publique
    game();
    game(int version); // permet de creer une game en fonction de la version demandée
    ~game();
    void test(Smoke s);
    void paintEvent(QPaintEvent *pe);
    void addObject(Objet *o); // pour que les lock soient changés
    void addSmoke(Smoke *s);
    void addItems();
    void addSmokeyItemsLite();
    void addSmokeyItemsDark();
    void testGame();
    void drawBackground ( QPainter * painter, const QRectF & rect );

public slots:
    void isGameOver();
};

#endif // GAME_H
