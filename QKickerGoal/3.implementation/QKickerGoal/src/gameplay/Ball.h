/**
 * @file Ball.h
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * Last modification : 2014, November 15th, by : Nouaim Souiki
*/
#ifndef BALL_H
#define BALL_H

#include "../engine/MovableEntity.h"

class Field;

/**
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * @brief The Ball class represent a simple foot ball.
 */
class Ball : public MovableEntity
{
private:
    static QMap<QString, QPixmap*> pixmaps;
    Field * m_field;
    bool m_rotation;

public:
    Ball(Field * field);
    ~Ball();
    QPointF move(Direction dir) override;
    void disableRotation();
    void enableRotation();
protected:
    virtual QPointF computeInitPosition() override;
    void loadPixmaps();
    virtual bool rotate() override;
private:
    virtual void timerEvent(QTimerEvent *) override;
    bool isMoving();
};

#endif // BALL_H
