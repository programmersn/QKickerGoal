/**
 * @file Avatar.h
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * Last modification : 2014, November 22th, by : Nouaim Souiki
*/
#ifndef AVATAR_H
#define AVATAR_H

#include "Footballer.h"

/**
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * @brief The Avatar class represent an avatar's gamer, which is a focusable
 *        footballer.
 */
class Avatar : public Footballer
{
private:
    bool m_focused;

public:
    Avatar(Field * field, Ball * ball, Team * team = nullptr,
           bool hasKickOff = false, bool focused = true);
    /**
     * @brief Destructor
     */
    virtual ~Avatar();
    /**
     * @brief Reimplement the MovableEntity::computeInitPosition()
     */
    virtual QPointF computeInitPosition() override;
    /**
     * @brief Decide if this avatar has got the focus.
     * @return true if the avatar has got the focus, false otherwise.
     */
    bool hasFocus();
    /**
     * @brief setFocus
     */
    void setFocus();
    /**
     * @brief unsetFocus
     */
    void unsetFocus();
    virtual void reinit() override;
};

#endif // AVATAR_H
