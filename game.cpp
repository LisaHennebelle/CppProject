#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
#include <QRadioButton>
#include "Objet.h"
#include "sac.h"
#include <QList>
#include <list>

game::game(int version)
{

    //imposer le timer de jeu à 3 minutes
    timerJeu->setSingleShot(true);
    timerJeu->start(180000);
    // taille des listes imposée

    //smokey_itemsLite->resize(NUM_SMOKE);
    mb->setText(" Congratulations!!! ");

    // creation du background bg

    background *bg = new background(version);
    scenery->addItem(bg);


    // ------ test du type de jeu ------ //
if (version ==  0){  //LITE

            // ajout de la liste des objet et ajout à la scene
            addItems();
            // creation de la variable sac
            Sac * sac = new Sac();
            sac->setFlag(QGraphicsItem::ItemIsFocusable);
            sac->setFocus();
            scenery ->addItem(sac);
            //ajout de la liste des smokey items et ajout à la scene
            addSmokeyItemsLite();

            //ajout d'une chausette
            Objet * chaussette = new Objet("chaussette");
            chaussette->addPixmapnew();
            itemsLite->push_back(chaussette);
            scenery->addItem(chaussette);
            chaussette->setFlag(QGraphicsItem::ItemIsFocusable);
            chaussette->setFocus();
            chaussette -> setPos(chaussette->x() + 100 , chaussette ->y() + 500);
            addObject(chaussette);

            qDebug("game LITE created with success");
}

    else if (version == 1)//DARK
        {
        // ajout de la liste des objet et ajout à la scene
        addItems();
        // creation de la variable sac
        Sac * sac = new Sac();
        sac->setFlag(QGraphicsItem::ItemIsFocusable);
        sac->setFocus();
        scenery ->addItem(sac);
        //ajout de la liste des smokey items et ajout à la scene
        addSmokeyItemsDark();

        //ajout d'une chausette
        Objet * chaussette = new Objet("chaussette");
        chaussette->addPixmapnew();
        itemsLite->push_back(chaussette);
        scenery->addItem(chaussette);
        chaussette->setFlag(QGraphicsItem::ItemIsFocusable);
        chaussette->setFocus();
        chaussette -> setPos(chaussette->x() + 100 , chaussette ->y() + 500);
        addObject(chaussette);
        }
    else {qDebug() << "il y a eu un probleme"; }

}

game::~game()
{
    qDebug()<<"game finished";
    //eliminitaion de tous les elements de la liste itemsLiteLite
    for (QList<Objet*>::iterator it_o=itemsLite->begin(); it_o !=itemsLite->end(); it_o++)
    {
        itemsLite -> erase(it_o);
    }
    // elimination de tous les elements de la liste smokey_items
    for (QList<Smoke*>::iterator it=smokey_itemsLite->begin(); it !=smokey_itemsLite->end(); it++)
    {
    smokey_itemsLite -> erase(it);
    }
}



void game::addObject(Objet * o)
{
    o->addPixmapnew();
    itemsLite->push_back(o);
    scenery->addItem(o);
    o->setFlag(QGraphicsItem::ItemIsFocusable);
    o->setFocus();
    qDebug()<<"objet "<<o->getName()<<" ajouté";
}

void game::addSmoke(Smoke *s)
{
    s->addPixmapnew();
    smokey_itemsLite->push_back(s);
    scenery->addItem(s);
    s->setFlag(QGraphicsItem::ItemIsFocusable);
    s->setFocus();
    qDebug()<<"smoke"<<s->getName()<<" ajouté";
}

void game::addItems()
{
    //items->resize(NUM_OBJET);


    // création des objets
    QString a = "A";
    int  i = 0;
    for (i = 0 ; i <NUM_OBJET ; i++) // remplissage de la liste des objets
    {
        QString name = "objet_ "+ a ;
        a = a+1;
        Objet *o = new Objet(name);
        itemsLite->push_back(o);
        qDebug() << "ajout de l'objet : "<< o->getName();

    }

}

void game::addSmokeyItemsLite()
{
    //--LOCOMOTIVE--//
    Smoke * loco = new Smoke("loco");
    addSmoke(loco); //ajout a la scene et creation du pixmap
    //--CHEMINEE--//
    Smoke * cheminee = new Smoke("cheminee");
    addSmoke(cheminee);//ajout a la scene et creation du pixmap
    //--CIGARETTE--//
    Smoke * cigarette = new Smoke("cigarette");
    addSmoke(cigarette);//ajout a la scene et creation du pixmap
    //--VOLCAN--//
    Smoke * volcan = new Smoke("volcan");
    addSmoke(volcan);
    //--JAMBON--//
    Smoke * jambon = new Smoke("jambon");
    addSmoke(jambon);

    //--ENCENS --//
    Smoke * encens = new Smoke("encens");
    addSmoke(encens);
    // set location

    loco->setPos(loco->x()+0, loco->y()+ 640);
    cheminee->setPos(cheminee->x()+ 20, cheminee->y()+ 140);
    cigarette->setPos(cigarette->x()+ 320, cigarette->y()+ 705);
    volcan ->setPos(volcan->x()+ 10, volcan->y()+ 290);
    jambon ->setPos(jambon->x()+ 640, jambon->x() + 610);

    encens -> setPos(encens->x() + 420, encens->y() + 465);



    // ajout des indices
    QPixmap * otto = new QPixmap(":/images/images/ottoDix");
    QPixmap *monet = new QPixmap(":/images/images/Monet");
    indice *indice_cigarette = new indice(" Petit moment artistique : \n Portrait of Silvia Von Harden - Otto DIX\n Le saviez-vous? \n Ce qu’on ne sait pas toujours, c’est qu’une fois allumée, la cigarette devient une véritable usine chimique. Sa combustion provoque\
 la formation de très nombreuses substances toxiques, dont les goudrons, des gaz toxiques (monoxyde de carbone, oxyde d’azote, acide cyanhydrique, ammoniac) et des métaux lourds\
 (cadmium, mercure, plomb, chrome).\n ");
    indice_cigarette->setIconPixmap(*otto);

    indice *indice_loco = new indice("Petit moment artistique : \n La Gare Saint-Lazare - Claude MONET\n Le saviez-vous? \n Les locomotives à vapeur conservent un certain succès pour les lignes de haute montagne\
 parce que la traction à vapeur est favorisée par la baisse de la pression atmosphérique due à l'altitude abaissant le point\
 d'ébullition de l'eau. Cela permet des économies de combustible et de meilleures performances.\n  ");
   indice_loco->setIconPixmap(*monet);


    indice *indice_cheminee = new indice("Ceci est un smokey");
    cigarette->associerIndice(indice_cigarette);
    loco->associerIndice(indice_loco);
    cheminee-> associerIndice(indice_cheminee);
}


void game::addSmokeyItemsDark()
{
    //--VAPOTEUR--//
    Smoke * vap = new Smoke("vapoteur");
    addSmoke(vap);
    vap-> setPos(vap->x() + 680, vap->y() + 720);
    qDebug()<< "not set yet";
}

void game::isGameOver()
{

     //qDebug()<<"is game over?"<< " all i wonder";
    if (timerJeu->isActive())
    {
        for (QList<Smoke*>::iterator it=smokey_itemsLite->begin(); it !=smokey_itemsLite->end(); ++it)
        {
           // qDebug()<< "testing "<<(*it)->getName();
            if ((*it)->x() < 800 || (*it)->y() < 500) // si un des objets fumée du jeu n'est pas dans le sac
            {
    //            qDebug()<<" pos de l'objet "<< (*it)->x() << "et " << (*it)->y();
                return; //on sort de la fonction
            }
        }

        //test en selcetionnant juste les objets dans la scene


        // une fois qu'on est arrivé là , tous les objets smoke sont dans le sac
        //c'est la fin du jeu
        over = 1;
        qDebug()<<"over is set a 1";
        mb->show();
        timer->stop(); //on stoppe le timer
    }
    else
    {
        QMessageBox * gameOver = new QMessageBox();
        gameOver->setAccessibleName("Game over");
        gameOver->setText("GAME OVER \n C'est la fin du temps imparti");
        gameOver->show();
        timer->stop();
    }
}
void game::testGame()
{

       QObject::connect(timer, SIGNAL(timeout()), this, SLOT(isGameOver()));
       qDebug()<<"let's start timer";
       if(over != 1)
       {
        timer->start(500);
       }
}


