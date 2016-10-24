/**
 * @file MovableEntity.cpp
 * @author Nouaim Souiki
 * @date 2014, November 19th
 * Last modification : 2014, November 21th, by : Nouaim Souiki
*/

#ifndef FOOTBALLER_H
#define FOOTBALLER_H

#include "../engine/MovableEntity.h"

class Field;
class Ball;
class Team;
class Avatar;
/**
 * @author Nouaim Souiki
 * @date 2014, November 19th
 * @brief The Footballer class represent an object footballer.
 * Provide generic methods to all types of footballers (focusable, like avatar,
 * or not, like goalkippers).
 */
class Footballer : public MovableEntity
{
protected:
    static QMap<QString, QPixmap*> pixmaps;
    static bool pixmapsLoaded;
    static Footballer * ballOwner;
    Field  * m_field;
    Ball   * m_ball;
    Team   * m_team;
    bool m_hasKickOff;

public:
    /**
     * @brief Constructor
     * @param field
     * @param ball
     * The Footballer knows, in any moment, on which field it is, and with which
     * ball it's playing on the field.
     */
    Footballer(Field * field, Ball * ball, Team * team = nullptr,
           bool hasKickOff = false);
    virtual ~Footballer();
    static Footballer * getBallOwner();
    bool isBallOwner();
    bool belongsTo(Team *team);
    virtual QPointF move(Direction dir);
    virtual bool pass();
    virtual bool shoot();
protected:
    /**
     * @brief Load all the Footballer's pixmaps in the static map m_pixmaps.
     */
    void loadPixmaps();
    /**
     * @brief Make the appropriate pixmap's key, according to the team color and
     * the direction of the footballer.
     * @param dir The current direction of the footballer;
     * @return The key created.
     * Note : Must be reimplemented in the subclasses, to make keys according to
     * the type of the footballer (e.g: a goalkeeper).
     */
    virtual QString makeAppropriatePixmapKey (Direction dir);
    /**
     * @brief Set the appropriate pixmap of key `key'.
     * @param key The key of the pixmap, in the pixmap map.
     */
    void setAppropriatePixmap (Direction dir);
    /**
     * @brief Replace the Footballer's ball front of its feet.
     * @param dir The direction of the Footballer
     */
    void replaceBallFrontOfFeet(Direction dir);

    Avatar* getPartner();
};

#endif // FOOTBALLER_H
