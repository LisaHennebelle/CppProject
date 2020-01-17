#include "game.h"
#include <QTimer>

game::game()
{

}


int game::isGameOver()
{
    return 1;
}

void game::testGame()
{
       QTimer * timer = new QTimer();
       connect(timer, SIGNAL(timeout()), this, SLOT(isGameOver()));
       timer->start();
}
