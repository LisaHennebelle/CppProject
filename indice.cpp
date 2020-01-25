#include "indice.h"
#include <string>
#include <QSpacerItem>
#include<QGridLayout>
#include <iostream>

// constructeurs
indice::indice()
{
    this-> QMessageBox::setText("not set");
    QSpacerItem* horizontalSpacer = new QSpacerItem(1000, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    //QSpacerItem* verticalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)this->layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 1, 1, layout->columnCount());
    this->setMinimumSize(QSize(1000,500));
}

indice::indice(QString message)
{
    this-> QMessageBox::setText(message);
    text = message;
    QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)this->layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    this->setMinimumSize(QSize(1000,500));
    //relObj->setName("unnamed");
}

indice::indice(QString message, QPixmap * qp )
{
     this-> QMessageBox::setText(message);
    this->setIconPixmap(*qp);
    QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)this->layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
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


