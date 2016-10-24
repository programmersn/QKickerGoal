/**
 * @file IntroGameState.h
 * @author Nouaim Souiki
 * @date 2014, November 14th
 * Last modification : 2014, November 24th, by : Nouaim Souiki
 */
#ifndef INTROGAMESTATE_H
#define INTROGAMESTATE_H

#include "../engine/gamestates/GameState.h"

/**
 * @author Nouaim Souiki
 * @brief The IntroGameState class is the introduction game's state
 * (i.e. before start playing game).
 */
class IntroGameState final:
        public GameState//,
    //    public Singleton<IntroGameState>
{
    //friend class Singleton<IntroGameState>;
private:
    static IntroGameState * instance;
    static QMap<QString, QPixmap*> pixmaps;

public:
    /**
     * @brief Destructor
     */
    virtual ~IntroGameState();
    static IntroGameState* getInstance();
    /**
     * @brief Reimplemented from GameState::manageEvents().
     */
    virtual void manageEvents(QKeyEvent *ev) override;
    virtual void clear() override;
private:
    /**
     * @brief Constructor
     */
    IntroGameState();
    void loadPixmaps();
    virtual void update() override;
};

#endif // INTROGAMESTATE_H
