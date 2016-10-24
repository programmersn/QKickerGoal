/**
 * @file MovableEntity.h
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * Last modification : 2014, November 17th, by : Nouaim Souiki
*/
#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H

#include <QVector2D>
#include "../engine/graphicsengine/GraphicsEntity.h"

class QPointF;

/**
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * @brief The MovableEntity class represent a graphics entity which can change
 * its own position.
 * Provide physics managing methods.
*/
class MovableEntity : public GraphicsEntity
{
public:
    /**
     * @brief The Direction enum represent the direction of the move of the
     * entitie.
     */
    enum class Direction {
        Right,
        Up,
        Left,
        Down,
        RightUp,
        RightDown,
        LeftUp,
        LeftDown,
        None
    };
protected:
    /**
     * @brief The initial position of the entity, on the bounding area.
     */
    QPointF m_initPosition;
    /**
     * @brief Area which contains the current entity.
     */
    QRectF m_boundingArea;
    /**
     * @brief Direction of the move of the avatar.
     */
    Direction m_direction;
private:
    /**
     * @brief The delta distance of the avatar's move.
     */
    QVector2D m_dMoveRect;
public:
    /**
     * @brief Constructor.
     * @param Area which contains the current entity.
     */
    MovableEntity(QRectF boundingArea);
    /**
     * @brief Destructor
     */
    virtual ~MovableEntity();
    /**
     * @brief Move the entity of one deltaDist step, int the direction `dir'.
     * @param dir The direction of the enity's move.
     * @return true if the move performed, false otherwise.
     */
    virtual QPointF move(Direction dir);
      /**
     * @brief Move the entity in its own direction following the 2d vector
     * vect.
     * @param vect The deplacement
     * @return true if the move performed, false otherwise.
     */
    virtual QPointF move(QVector2D vect);
    /**
     * @brief Set the entity on the position dest.
     * @param dest The new position.
     * @return true if the changement performed, false otherwise.
     */
    bool setPosition(const QPointF dest);
    /**
     * @brief Check if with its current position, the entity will still be
     * in its bounding area.
     * @return true if the entity is in its bounding area, false otherwise.
     */
    virtual bool inBoundingArea();
    /**
     * @brief Check if in the current position, the entity is in its bounding
     * area.
     * @param newPos The new entity's position to check.
     * @return true if the entity will be still in the bounding area,
     * false otherwise.
     */
    virtual bool inBoundingArea(QPointF newPos);
    /**
     * @brief Collision between the current movable entity and an other.
     * @param other The other entity.
     * @return true if it is collision, false otherwise.
     */
    virtual bool collidesWith (MovableEntity * other);
    virtual void reinit();
protected:
    /**
     * @brief Compute the intit position of the entitie on the area.
     * Note : must to be reimplemented to specify with more precision this
     * position, in the subclasses of MovableEntity.
     * @return The initial position.
     */
    virtual QPointF computeInitPosition();

    virtual bool rotate();
};

#endif // MOVABLEENTITY_H
