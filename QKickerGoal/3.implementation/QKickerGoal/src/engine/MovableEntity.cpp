/**
 * @file MovableEntity.cpp
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * Last modification : 2014, November 16th, by : Nouaim Souiki
*/

#include <iostream>
#include <QMap>
#include "MovableEntity.h"

MovableEntity :: MovableEntity(QRectF boundingArea)
    : GraphicsEntity(),
      m_boundingArea(boundingArea),
      m_direction(Direction::None),
      m_dMoveRect(QPointF(5,5))
{
    m_initPosition = this->computeInitPosition();
}

MovableEntity :: ~MovableEntity()
{

}

QPointF
MovableEntity :: computeInitPosition()
{
    return QPointF();
}

void
MovableEntity :: reinit()
{
    m_initPosition = this->computeInitPosition();
}

bool
MovableEntity :: inBoundingArea()
{
    return this->inBoundingArea(this->pos());
}

bool
MovableEntity :: inBoundingArea(QPointF newPos)
{
    return  newPos.x() > m_boundingArea.x()
            &&
            newPos.x() + this->getBoundingRectSize().width()
            < m_boundingArea.x() + m_boundingArea.width()
            &&
            newPos.y() > m_boundingArea.y()
            &&
            newPos.y() + this->getBoundingRectSize().height()
            < m_boundingArea.y() + m_boundingArea.height();
}

bool
MovableEntity ::collidesWith(MovableEntity * other)
{
    return !
            (this->x() + this->getBoundingRectSize().width() <= other->x()
             ||
             this->x() >= other->x() + other->getBoundingRectSize().width()
             ||
             this->y() + this->getBoundingRectSize().height() <= other->y()
             ||
             this->y() >= other->y() + other->getBoundingRectSize().height());
}

QPointF
MovableEntity :: move(Direction dir)
{
    QPointF newPos;
    this->m_direction = dir;
    switch (m_direction) {
    case Direction::RightUp:
        newPos = QPointF(this->pos().x()+m_dMoveRect.x()*2/3,
                         this->pos().y()-m_dMoveRect.y()*2/3);
        break;
    case Direction::RightDown:
        newPos = QPointF(this->pos().x()+m_dMoveRect.x()*2/3,
                         this->pos().y()+m_dMoveRect.y()*2/3);
        break;
    case Direction::LeftUp:
        newPos = QPointF(this->pos().x()-m_dMoveRect.x()*2/3,
                         this->pos().y()-m_dMoveRect.y()*2/3);
        break;
    case Direction::LeftDown:
        newPos = QPointF(this->pos().x()-m_dMoveRect.x()*2/3,
                         this->pos().y()+m_dMoveRect.y()*2/3);
        break;
    case Direction::Right:
        newPos = QPointF(this->pos().x()+m_dMoveRect.x(), this->pos().y());
        break;
    case Direction::Up:
        newPos = QPointF(this->pos().x(), this->pos().y()-m_dMoveRect.y());
        break;
    case Direction::Left:
        newPos = QPointF(this->pos().x()-m_dMoveRect.x(), this->pos().y());
        break;
    case Direction::Down:
        newPos = QPointF(this->pos().x(), this->pos().y()+m_dMoveRect.y());
        break;
    case Direction::None:
    default: break;
    }
    if (this->setPosition(newPos))
        return newPos;
    return this->pos();
}

QPointF
MovableEntity :: move (QVector2D vect)
{
    QVector2D tmp = m_dMoveRect;
    m_dMoveRect = vect;
    QPointF dest = this->move(m_direction);
    m_dMoveRect = tmp;
    return dest;
}

bool
MovableEntity :: setPosition (const QPointF dest)
{
    //! @todo Add collisions with others entities
    if (this->inBoundingArea(dest)) {
        this->setPos(dest);
        return true;
    }
    return false;
}

bool
MovableEntity :: rotate()
{
}

