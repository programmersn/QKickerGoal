/**
 * @file PlayingGameState.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification : 2014, November 16th, by : Nouaim Souiki
 */

#ifndef PLAYINGGAMESTATE_H
#define PLAYINGGAMESTATE_H

#include <QTimer>
#include "../patterns/Singleton.h"
#include "../engine/gamestates/GameState.h"
#include "../engine/graphicsengine/GraphicsEntity.h"

class GraphicsScene;
class Field;
class Ball;
class Team;
class Avatar;

/**
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * @brief The PlayingGameState class is the state where user play the game.
 */
class PlayingGameState final :
        public QObject,
        public GameState//,
        //public Singleton<PlayingGameState>
{
    //friend class Singleton<PlayingGameState>;
private:
    static PlayingGameState * instance;
    typedef struct {
        bool up;
        bool right;
        bool left;
        bool down;
        bool shoot;
        bool pass;
        bool swap;
        bool pause;
    } PlayingKeys;
    Field * m_field;
    Ball * m_ball;
    Team * m_rightTeam;
    Team * m_leftTeam;
    PlayingKeys m_rightTeamKey, m_leftTeamKey;
    void update (Team * team, PlayingKeys teamKey);
public:
    /**
     * @brief Destructor.
     */
    virtual ~PlayingGameState();
    static PlayingGameState * getInstance();
    /**
     * @brief Implement GameState::manageEvents().
     */
    virtual void manageEvents(QKeyEvent *ev) override;

    virtual void clear() override;
    void reinit();
private:

   /**
     * @brief Constructor.
     */
    PlayingGameState();
    virtual void update() override;
    virtual void timerEvent(QTimerEvent *) override;
    void initKeys();
    void setKeysAs(QKeyEvent * ev, bool activation);
    /**
     * @brief Implement GameState::update()
     */
    void swapFocus(Team * team);
    Avatar * getFocused(Team * team);
};


#endif // PLAYINGGAMESTATE_H
