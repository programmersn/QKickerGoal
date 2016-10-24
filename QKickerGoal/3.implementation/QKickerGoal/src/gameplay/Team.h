/**
 * @file Team.h
 * @author Nouaim Souiki
 * @date 2014, November 18th
 * Last modification : 2014, November 18th, by : Nouaim Souiki
*/
#ifndef TEAM_H
#define TEAM_H

#include "Field.h"

class Footballer;
class Avatar;
class GoalKeeper;
class Field;
class Ball;

/**
 * @author Nouaim Souiki
 * @date 2014, November 18th
 * @brief The Team class represents a mini-football team, composed of only
 * 2 footballers (i.e: avatars) and 1 goalkeeper.
 * @todo Add the goalkeeper.
 */
class Team
{
public:
    enum class Color { Red, Blue };
private :
    Field::Half m_halfField;
    Color m_color;
    bool m_hasKickOff;
    Footballer * m_avatar1;
    Footballer * m_avatar2;
    Footballer * m_goalKeeper;

public:
    Team(Field * field, Ball * ball, Field::Half halfField, Color color,
         bool hasKickOff = false);
    virtual ~Team();
    bool hasKickOff() const;
    bool inRightHalfField() const;
    bool inLeftHalfField() const;
    Color getColor() const;
    Avatar* getAvatar1() const;
    Avatar* getAvatar2() const;
    GoalKeeper* getGoalKeeper() const;
    void reinit();
};

#endif // TEAM_H
