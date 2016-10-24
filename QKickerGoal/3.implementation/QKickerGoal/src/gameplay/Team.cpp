/**
 * @file Team.cpp
 * @author Nouaim Souiki
 * @date 2014, November 18th
 * Last modification : 2014, November 18th, by : Nouaim Souiki
*/
#include "Team.h"
#include "Footballer.h"
#include "Avatar.h"
#include "GoalKeeper.h"

Team :: Team(Field * field, Ball * ball, Field::Half halfField, Color color,
             bool hasKickOff)
    : m_halfField(halfField),
      m_color(color),
      m_hasKickOff(hasKickOff),
      m_avatar1(nullptr),
      m_avatar2(nullptr),
      m_goalKeeper(nullptr)
{
    m_avatar1    = new Avatar(field, ball, this, hasKickOff);
    m_avatar2    = new Avatar(field, ball, this, false, false);
    m_goalKeeper = new GoalKeeper(field, ball, this);

    //m_goalkeeper = new GoalKeeper(field, ball);
}

Team :: ~Team()
{
    delete m_avatar1;
    delete m_avatar2;
    delete m_goalKeeper;
}

void
Team :: reinit()
{
    m_avatar1->reinit();
    m_avatar2->reinit();
    m_goalKeeper->reinit();
}

bool
Team :: hasKickOff () const
{
    return m_hasKickOff;
}

bool
Team :: inRightHalfField() const
{
    if (m_halfField == Field::Half::Right)
        return true;
    return false;
}


bool
Team :: inLeftHalfField() const
{
    if (m_halfField == Field::Half::Left)
        return true;
    return false;
}

Team::Color
Team :: getColor() const
{
    return m_color;
}

Avatar*
Team :: getAvatar1() const
{
    return dynamic_cast<Avatar*>(m_avatar1);
}

Avatar*
Team :: getAvatar2() const
{
    return dynamic_cast<Avatar*>(m_avatar2);
}

GoalKeeper*
Team :: getGoalKeeper() const
{
    return dynamic_cast<GoalKeeper*>(m_goalKeeper);
}
