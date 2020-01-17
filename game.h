#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "Objet.h"
#include "Smoke.h"
#include "list"

class game : public QObject
{
    Q_OBJECTS
    std::list<Objet> items;
    std::list<Smoke> smokey_items;


public:
    game();
    void testGame();
public slots:
    int isGameOver();
};

#endif // GAME_H
