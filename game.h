#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "Objet.h"
#include "Smoke.h"
#include "list"
#define NUM_OBJET 2
#define NUM_SMOKE 3

class game : public QObject
{
    Q_OBJECT
    std::list<Objet> *items = new std::list<Objet> ;
    std::list<Smoke> *smokey_items = new std::list<Smoke> ;
    int over;

public:
    game();
    ~game();
    void addObject(Objet & o); // pour que les lock soient changés
    void addSmoke(Smoke & s);
    void testGame();

public slots:
    void isGameOver();
};

#endif // GAME_H
