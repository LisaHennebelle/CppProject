#include "indice.h"
#include <string>
#include <iostream>

// constructeurs
indice::indice()
{
    this-> QMessageBox::setText("not set");
    this->setMinimumSize(QSize(1000,500));
}

indice::indice(QString message)
{
    this-> QMessageBox::setText(message);
    text = message;
    this->setMinimumSize(QSize(1000,500));
    //relObj->setName("unnamed");
}

indice::indice(QString message, QPixmap * qp )
{
     this-> QMessageBox::setText(message);
    this->setIconPixmap(*qp);
    this->setMinimumSize(QSize(1000,500));
}

indice::indice(const indice &i)
{
    //this->relObj =i.relObj;
    this->text = i.text;
    this->setMinimumSize(QSize(1000,500));
}
//setter

void indice::setText(QString message)
{
   // text = message;
    this->QMessageBox::setText(message);
    std::cout<<"on est dans setText()"<<std::endl;
    this-> exec();
}


void indice::show()
{
    //this->QMessageBox::setText("The document has been modified.");
    this->exec();
}


