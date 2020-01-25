
#include <QApplication>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include "Smoke.h"
#include "game.h"
#include "background.h"
#include <QGraphicsView>
#include<QPushButton>
#include <unistd.h>
#include<string>



int main(int argc, char *argv[])

{
                QApplication a(argc, argv);

               // QGraphicsScene * scene= new QGraphicsScene();
                QMessageBox *start = new QMessageBox();
                int kindGame = 0;
                start->setText("\
            Vous allez jouer a notre jeu 'La fumée autour de nous'\n\n\
            Le but est simple :\n\
            Retrouvez les objets relatifs à la fumée et mettez les dans le sac avec les flèches de votre clavier!\nPour sélectionner un autre objet, cliquez dessus avec la souris\
            \nN'hésitez pas à tester d'autres touches, vous aurez peut-être des surprises ...                    \
            \nMais attention vous n'aurez que 3 minutes");
                int retour = start->exec(); // message d'acceuil

                //---------Selection du type de jeu ----------//
                if (retour == QMessageBox::Ok)
                {
                QMessageBox *debut = new QMessageBox();
                QPushButton *bLite = new QPushButton("Jouer en version Lite");
                QPushButton *bDark = new QPushButton("Jouer en version Dark");
                debut->addButton(bLite,QMessageBox::AcceptRole);
                debut->addButton(bDark,QMessageBox::AcceptRole);
                debut->setButtonText(0, "Je choisis un jeu en version Lite");
                debut->setButtonText(1, "Je choisis un jeu en version Dark");
                debut->setWindowTitle("Quel type de jeu voulez vous?");
                 // selection du type de jeu
                debut->exec();

                // ----- Détermination du type de jeu en fonction du bouton selectionné ----- //

                if (debut->clickedButton() == bLite)
                {
                    bLite->setDisabled(true);
                    bDark->setDisabled(true);
                    kindGame = 0;
                }
                if (debut->clickedButton() == bDark)
                {
                    bLite->setDisabled(true);
                    bDark->setDisabled(true);
                    kindGame = 1;
                }
                game * gameChoisie = new game(kindGame);


                QGraphicsView * view = new QGraphicsView(gameChoisie->scenery);
                  view ->resize(1200, 788);
                gameChoisie->testGame();
                view->show();

                a.exec();


                }
                return 0;
}
