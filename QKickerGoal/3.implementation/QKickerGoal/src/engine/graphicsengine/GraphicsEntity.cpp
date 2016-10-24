/**
 * @file GraphicsEntity.cpp
 * @author Nouaim Souiki
 * Last modification : 2014, November 13th, by : Nouaim Souiki
*/
#include <iostream>
#include "GraphicsEntity.h"

GraphicsEntity :: GraphicsEntity()
    : QGraphicsPixmapItem (),
      m_entityPixmap(nullptr)
{
    // TODO : add pixmap to the scene.
    std::cout << "--GraphicsEntity::GraphicsEntity() done--" << std::endl;
}


GraphicsEntity :: GraphicsEntity(QPixmap * entityPixmap)
    : QGraphicsPixmapItem (*entityPixmap),
      m_entityPixmap(entityPixmap)
{
    // TODO : add pixmap to the scene.
    std::cout << "--GraphicsEntity::GraphicsEntity() done--" << std::endl;
}

GraphicsEntity :: ~GraphicsEntity()
{
    delete m_entityPixmap;
}

QSizeF
GraphicsEntity :: getBoundingRectSize()
{
    return this->boundingRect().size();
}

