#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
#include "Objet.h"
#include "sac.h"
#include <QList>
#include <list>

game::game()
{
    // taille des listes imposée
    QMessageBox * debut = new QMessageBox();
    debut->setText("Vous allez jouer a notre jeu 'La fumée autour de nous'\n Le but est simple :\
retrouvez les objets relatifs à la fumée et mettez les dans le sac avec les flèches de votre clavier!\
\n N'hésitez pas à tester d'autres touches, vous aurez peut-être des surprises ... ");
    debut->show();

    //smokey_items->resize(NUM_SMOKE);
    mb->setText("Congrats");
    over = 0;// over initialisé à 0
    // creation du background bg
    background *bg = new background();
    scenery->addItem(bg);

    // ajout de la liste des objet et ajout à la scene
    addItems();
    // creation de la variable sac
    Sac * sac = new Sac();
    sac->setFlag(QGraphicsItem::ItemIsFocusable);
    sac->setFocus();
    scenery ->addItem(sac);
    //ajout de la liste des smokey items et ajout à la scene
    addSmokeyItems();

    qDebug("game created with success");
}
game::~game()
{
    qDebug()<<"game finished";
    //eliminitaion de tous les elements de la liste items
    for (QList<Objet*>::iterator it_o=items->begin(); it_o !=items->end(); it_o++)
    {
        items -> erase(it_o);
    }
    // elimination de tous les elements de la liste smokey_items
    for (QList<Smoke*>::iterator it=smokey_items->begin(); it !=smokey_items->end(); it++)
    {
    smokey_items -> erase(it);
    }
}



void game::addObject(Objet * o)
{
    o->addPixmapnew();
    items->push_back(o);
    scenery->addItem(o);
    o->setFlag(QGraphicsItem::ItemIsFocusable);
    o->setFocus();
    qDebug()<<"objet "<<o->getName()<<" ajouté";
}

void game::addSmoke(Smoke *s)
{
    s->addPixmapnew();
    smokey_items->push_back(s);
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
        items->push_back(o);
        qDebug() << "ajout de l'objet : "<< o->getName();

    }

}

void game::addSmokeyItems()
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
    //--VAPOTEUR--//
    Smoke * vap = new Smoke("vapoteur");
    addSmoke(vap);
    //--ENCENS --//
    Smoke * encens = new Smoke("encens");
    addSmoke(encens);
    // set location

    loco->setPos(loco->x()+0, loco->y()+ 750);
    cheminee->setPos(cheminee->x()+ 90, cheminee->y()+ 180);
    cigarette->setPos(cigarette->x()+ 400, cigarette->y()+ 825);
    volcan ->setPos(volcan->x()+ 40, volcan->y()+ 340);
    jambon ->setPos(jambon->x()+ 740, jambon->x() + 700);
    vap-> setPos(vap->x() + 1285, vap->y() + 790);
    encens -> setPos(encens->x() + 520, encens->y() + 555);



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

void game::isGameOver()
{
        //qDebug()<<"is game over?"<< " all i wonder";
    for (QList<Smoke*>::iterator it=smokey_items->begin(); it !=smokey_items->end(); ++it)
    {
       // qDebug()<< "testing "<<(*it)->getName();
        if ((*it)->x() < 1100 || (*it)->y() < 600) // si un des objets fumée du jeu n'est pas dans le sac
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
void game::testGame()
{

       QObject::connect(timer, SIGNAL(timeout()), this, SLOT(isGameOver()));
       qDebug()<<"let's start timer";
       if(over != 1)
       {
        timer->start(500);
       }
}


