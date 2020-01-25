#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>
#include <QRadioButton>
#include "Objet.h"
#include "sac.h"
#define SACX 800
#define SACY 500
#include <QList>
#include <list>

game::game(int version)
{

    //imposer le timer de jeu à 3 minutes
    timerJeu->setSingleShot(true);
    timerJeu->start(180000);
    // taille des listes imposée


    // creation du background bg

    background *bg = new background(version);
    scenery->addItem(bg);


    // ------ test du type de jeu ------ //
if (version ==  0){  //LITE

            // ajout de la liste des objet et ajout à la scene
            addItemsLite();
            // creation de la variable sac
            Sac * sac = new Sac();
            sac->setFlag(QGraphicsItem::ItemIsFocusable);
            sac->setFocus();
            scenery ->addItem(sac);
            //ajout de la liste des smokey items et ajout à la scene
            addSmokeyItemsLite();

            qDebug("game LITE created with success");
}

    else if (version == 1)//DARK
        {

        // creation de la variable sac
        Sac * sac = new Sac();
        sac->setFlag(QGraphicsItem::ItemIsFocusable);
        sac->setFocus();
        scenery ->addItem(sac);
        //ajout de la liste des smokey items et ajout à la scene
        addSmokeyItemsDark();
        // ajout de la liste des objet et ajout à la scene
        addItemsDark();
        }


    else {qDebug() << "il y a eu un probleme"; }

}

game::~game()
{
    qDebug()<<"game finished";
    //elimination de tous les elements de la liste itemsLiteLite
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

void game::addItemsLite()
{
    // création des objets

    //---CHAUSSETTE---//
        Objet *o = new Objet("chaussette");
        addObject(o);
        o->setPos(o->x()+ 710, o->y() + 550);


     //---MOULIN---//
        Objet *moulin = new Objet("moulin");
        addObject(moulin);
        moulin->setPos(moulin->x()+ 1060, moulin->y() + 30);


        //---GLOBE---//
        Objet *globe = new Objet("globe");
        addObject(globe);
        globe->setPos(globe->x()+ 560, globe->y() + 570);


        //---FLEURS---//
        Objet *fleurs = new Objet("fleurs");
        addObject(fleurs);
        fleurs->setPos(fleurs->x()+ 240, fleurs->y() + 430);
}

void game::addItemsDark()
{
    //---PIANO---//
        Objet *piano = new Objet("piano");
        addObject(piano);
        piano->setPos(piano->x()+ 20, piano->y() + 400);
        qDebug() << "ajout de l'objet : "<< piano->getName();

        //---DALMATIEN--//
            Objet *dalmatien = new Objet("dalmatien");
            addObject(dalmatien);
            dalmatien->setPos(dalmatien->x()+ 280, dalmatien->y() +570);
        //---DOMINO--//
            Objet *domino = new Objet("domino");
            addObject(domino);
            domino->setPos(domino->x()+ 770, domino->y() + 590);
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
    QPixmap *douillet = new QPixmap(":/images/images/douillet");
    QPixmap *volcanique = new QPixmap(":/images/images/volcan2");
    QPixmap *ham = new QPixmap(":/images/images/ham");
    QPixmap *parfum = new QPixmap(":/images/images/parfum");




    indice *indice_cigarette = new indice(" Petit moment artistique : \n Portrait of Silvia Von Harden - Otto DIX\n Le saviez-vous? \n Ce qu’on ne sait pas toujours, c’est qu’une fois allumée, la cigarette devient une véritable usine chimique. Sa combustion provoque\
 la formation de très nombreuses substances toxiques, dont les goudrons, des gaz toxiques (monoxyde de carbone, oxyde d’azote, acide cyanhydrique, ammoniac) et des métaux lourds\
 (cadmium, mercure, plomb, chrome).\n ");
    indice_cigarette->setIconPixmap(*otto);

    indice *indice_loco = new indice("Petit moment artistique : \n La Gare Saint-Lazare - Claude MONET\n Le saviez-vous? \n Les locomotives à vapeur conservent un certain succès pour les lignes de haute montagne\
 parce que la traction à vapeur est favorisée par la baisse de la pression atmosphérique due à l'altitude abaissant le point\
 d'ébullition de l'eau. Cela permet des économies de combustible et de meilleures performances.\n  ");
   indice_loco->setIconPixmap(*monet);


    indice *indice_cheminee = new indice("En 1965, la cheminée est franchement tendance et tous les foyers veulent en posséder une, qu’elle soit vraie ou fausse, ancienne ou moderne! \n "
                                         "Aujourd’hui, la cheminée est toujours symbole de convivialité et un élément de décoration à part entière avec des modèles ultra design ou plus traditionnels");

    indice_cheminee->setIconPixmap(*douillet);

    indice *indice_volcan= new indice("Dans la mythologie maori, les volcans Taranaki et Ruapehu tombèrent tous les deux amoureux du volcan Tongariro suite à quoi une violente dispute éclata.\n"
                                      "C'est pourquoi, aujourd'hui encore, aucun Maori ne vit entre les deux volcans colériques, de peur de se retrouver pris au milieu de la dispute.");
    indice_volcan->setIconPixmap(*volcanique);



    indice *indice_jambon = new indice("Suspends un violon,un jambon à ta porte et tu verras rappliquer!");
    indice_jambon->setIconPixmap(*ham);



    indice *indice_encens=new indice("Sous le charme du parfum mais sans s'en rendre compte,"
                                     "le gens changeaient de physionomie,d'attitude,de sentiments");
    indice_encens->setIconPixmap(*parfum);

    cigarette->associerIndice(indice_cigarette);
    loco->associerIndice(indice_loco);
    cheminee-> associerIndice(indice_cheminee);
    volcan->associerIndice(indice_volcan);
    jambon->associerIndice(indice_jambon);
    encens->associerIndice(indice_encens);


}


void game::addSmokeyItemsDark()
{
    //--VAPOTEUR--//
    Smoke * vap = new Smoke("vapoteur");
    addSmoke(vap);
    vap-> setPos(vap->x() + 1050, vap->y() + 450);

    //---AUDREY SMOKING---//
    Smoke* audrey = new Smoke("audrey");
    addSmoke(audrey);
    audrey->setPos(audrey->x() + 520, audrey ->y() +70);

    //---CAFE----//
    Smoke* cafe = new Smoke("cafe");
    addSmoke(cafe);
    cafe->setPos(cafe->x() + 60, cafe->y() +430);

    //--DRAGON---//
    Smoke * dragon = new Smoke("dragon");
    addSmoke(dragon);
    dragon->setPos(dragon->x() +245 , dragon->y() + 310 );

    //--BOITE D'ALUMETTES --//
    Smoke * boite = new Smoke("boiteAlumettes");
    addSmoke(boite);
    boite->setPos(boite->x() +1015 ,boite->y() + 245);

    //ajout des indices
    QPixmap *hepburn = new QPixmap(":/images/images/hepburn");
    QPixmap *vapoteuse = new QPixmap(":/images/images/vapo");

    indice *indice_audrey=new indice("La beauté d’une femme n’est pas dans les vêtements qu’elle porte, la figure qu’elle affiche ou la manière dont elle se coiffe les cheveux. La beauté d’une femme se voit dans ses yeux car ils sont la porte de son coeur, l’endroit où réside son amour.");
    indice_audrey->setIconPixmap(*hepburn);
    audrey->associerIndice(indice_audrey);

    indice *indice_vapoteuse=new indice("La vapoteuse diffuse de la vapeur, avec ou sans nicotine, pour vous donner l'impression de tirer sur une véritable cigarette ");
    indice_vapoteuse->setIconPixmap(*vapoteuse);
    vap->associerIndice(indice_vapoteuse);

    indice *indice_dragon = new indice("Contrairement à leurs homologues européens, les dragons asiatiques, bien qu'associés aux forces de la nature, sont dangereux mais pas vraiment hostiles. \n"
                                       " Ils ne montrent pas le caractère souvent violent des dragons occidentaux.");
    dragon->associerIndice(indice_dragon);

    indice *indice_cafe = new indice("Au cours du XVIIIe siècle, la boisson connaît un grand succès en Europe, et pour répondre à la demande, les colons européens introduisent la culture du café dans de nombreux pays tropicaux. Au XIXe siècle,"
                                     " l'offre insuffisante a stimulé l'usage de divers substituts au goût proche, comme la racine de chicorée. ");
    cafe->associerIndice(indice_cafe);

    indice *indice_alumettes = new indice("La collection des boîtes d'allumettes porte le nom de philuménie. Elle est pratiquée de longue date par d'infatigables chercheurs, évoqués par Anatole France, Le Crime de Sylvestre Bonnard, membre de l'Institut.\n"

                                          "La plus ancienne boîte d'allumettes française connue, 'Pyrogènes', très joliment ornée, est conservée à la Bibliothèque nationale. ");
    boite ->associerIndice(indice_alumettes);




}

void game::isGameOver()
{

   if (timerJeu->isActive())
    {
        for (QList<Smoke*>::iterator it=smokey_itemsLite->begin(); it !=smokey_itemsLite->end(); ++it)
        {
           // qDebug()<< "testing "<<(*it)->getName();
            if ((*it)->x() < SACX || (*it)->y() < SACY) // si un des objets fumée du jeu n'est pas dans le sac
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
        int runtime = (180000 - timer->remainingTime())/1000;//nombre de millisecondes qui se sont écoulées depuis le debut du timer
        QString score;
        score= "Votre score est de :" + QString::number(runtime) + " secondes de jeu";
        score += "/n Ce qui fait " + QString::number(runtime/60) + ":" +QString::number(runtime%60) + "minutes" ;
        mb->setText(" Félicitations!!! \n" + score );
        mb->exec();
        timer->stop();

    }
    else
    {
        QMessageBox * gameOver = new QMessageBox();
        gameOver->setAccessibleName("Game over");
        gameOver->setText("GAME OVER \n C'est la fin du temps imparti");
        gameOver->exec();
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


