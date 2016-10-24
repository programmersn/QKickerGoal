/**
 * @file MovableEntity.cpp
 * @author Nouaim Souiki
 * @date 2014, November 21th
 * Last modification : 2014, November 21th, by : Nouaim Souiki
*/

#include "GoalKeeper.h"
#include "Team.h"

GoalKeeper :: GoalKeeper (Field * field, Ball * ball, Team * team)
    : Footballer(field, ball, team, false)   // A goalkipper never has kickoff
{
    m_initPosition = this->computeInitPosition();
    this->setPosition(m_initPosition);
}

GoalKeeper :: ~GoalKeeper()
{
}

QPointF
GoalKeeper :: computeInitPosition()
{
    QSizeF fieldSize = m_field->getBoundingRectSize();

    if (m_team->inRightHalfField()) {
        this->setAppropriatePixmap(MovableEntity::Direction::Left);
        return QPointF(4*fieldSize.width()/5, fieldSize.height()/2);
    }
    else if (m_team->inLeftHalfField()) {
        this->setAppropriatePixmap(MovableEntity::Direction::Right);
        return QPointF(fieldSize.width()/5, fieldSize.height()/2);
    }
    return QPointF();
}

void
GoalKeeper :: reinit()
{
    this->computeInitPosition();
}

QString
GoalKeeper :: makeAppropriatePixmapKey (MovableEntity::Direction dir)
{
    return Footballer::makeAppropriatePixmapKey(dir).append("_goal");
}

