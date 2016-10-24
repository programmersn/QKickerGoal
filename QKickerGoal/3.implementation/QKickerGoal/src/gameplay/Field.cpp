/**
 * @file Field.cpp
 * @author Amine Rhazi
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */
#include <iostream>
#include <cassert>
#include <QPixmap>
#include "Field.h"

QMap<QString, QPixmap*>
Field :: pixmaps =
{
};

Field :: Field() :
    GraphicsEntity(),
    m_size(this->getBoundingRectSize())
{
    this->loadPixmaps();
    this->setPixmap(*Field::pixmaps.value("field_day"));
 //   this->pixmap().scaled(0.9,0.8, Qt::KeepAspectRatio);
}

Field :: ~Field()
{
    std::cout << "**PlayingGameState** : releasing field datas ..."
              << std::endl;
    Field::pixmaps.clear();
   //>! @todo Add `cout << "Releasing pixmap ...'
}

QSizeF
Field :: getSize() const
{
    return m_size;
}
void
Field :: loadPixmaps()
{
    Field::pixmaps.insert("field_day",
                          new QPixmap(":datas/images/playinggamestate/field/"
                                      "field-background.jpg"));
}
