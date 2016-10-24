/**
 * @file MovableEntity.cpp
 * @author Nouaim Souiki
 * @date 2014, November 21th
 * Last modification : 2014, November 21th, by : Nouaim Souiki
*/
#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include "Footballer.h"

/**
 * @author Nouaim Souiki
 * @date 2014, November 21th
 * @brief The GoalKeeper class represent footbal goalkeeper.
 */
class GoalKeeper : public Footballer
{
public:
    GoalKeeper(Field * field, Ball * ball, Team * team);
    virtual ~GoalKeeper();

    virtual void reinit() override;
protected:
    /**
     * @brief Reimplement MovableEntity::computeInitPosition().
     */
    virtual QPointF computeInitPosition() override;
    /**
     * @brief Reimplement Footballer::makeAppropriatePixmapKey().
     */
    virtual QString makeAppropriatePixmapKey(Direction dir) override;

};

#endif // GOALKEEPER_H
