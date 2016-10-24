/**
 * @file Avatar.h
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * Last modification : 2014, November 17th, by : Nouaim Souiki
*/
#include <iostream>
#include "Avatar.h"
#include "Field.h"
#include "Team.h"

Avatar :: Avatar(Field * field, Ball * ball, Team * team, bool hasKickOff,
                 bool focus)
    : Footballer(field, ball, team, hasKickOff),
      m_focused(focus)
{
    // If this Footballer has the kickoff, then it is the owner of the ball.
    if (this->m_hasKickOff)
        Footballer::ballOwner = this;
    m_initPosition = this->computeInitPosition();
    this->setPosition(m_initPosition);
}

Avatar :: ~Avatar()
{
}

QPointF
Avatar :: computeInitPosition()
{
    QSizeF fieldSize = m_field->getBoundingRectSize();

    qreal delta = 10;

    if (m_team->hasKickOff()) {// If this Footballer's team has got the kick off
        if (this->m_hasKickOff) {
            this->setAppropriatePixmap(Direction::Up);
            if (m_team->inRightHalfField())
                return QPointF(fieldSize.width()/2-15+delta,
                               fieldSize.height()/2-5+delta);
            else return QPointF(fieldSize.width()/2-15-delta,
                                fieldSize.height()/2+20-delta);
        }
        else {
            this->setAppropriatePixmap(Direction::Down);
            if (m_team->inRightHalfField())
                return QPointF(fieldSize.width()/2-15+delta,
                               fieldSize.height()/2-60+delta);
            else
                return QPointF(fieldSize.width()/2-15-delta,
                               fieldSize.height()/2-40-delta);
        }
    }
    else {    // If this Footballer's team hasn't got the kickoff.
        if (this->hasFocus()) {    // but this Footballer is focused
            if(m_team->inRightHalfField()) {
                this->setAppropriatePixmap(Direction::Left);
                return QPointF(3*fieldSize.width()/4,
                               fieldSize.height()/4);
            }
            else {
                this->setAppropriatePixmap(Direction::Right);
                return QPointF(fieldSize.width()/4,
                               fieldSize.height()/4+500);
            }
        }
        else {    // but this Footballer is not focused
            if(m_team->inRightHalfField()) {
                this->setAppropriatePixmap(Direction::Left);
                return QPointF(3*fieldSize.width()/4,
                               3*fieldSize.height()/4);

            }
            else {
                this->setAppropriatePixmap(Direction::Right);
                return QPointF(fieldSize.width()/4,
                               fieldSize.height()/4+70);
            }
        }
    }
    return QPointF();
}

void
Avatar :: reinit()
{
    this->computeInitPosition();
}

bool
Avatar :: hasFocus()
{
    return m_focused;
}

void
Avatar :: setFocus()
{
    m_focused = true;
}

void
Avatar :: unsetFocus()
{
    if (!this->isBallOwner())
        m_focused = false;
}


