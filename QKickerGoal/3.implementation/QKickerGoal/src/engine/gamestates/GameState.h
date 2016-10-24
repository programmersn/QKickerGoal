/**
 * @file GameState.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification :
 * - 2014, November 24th, by : Nouaim Souiki (Changed destructor access right to
 *   public).
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Kernel.h"
#include "../../engine/graphicsengine/GraphicsScene.h"

/**
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * @brief The GameState class represent an abstract game state.
 * An game state is a system component which make its own scene and manage
 * its own events.
 * Inherit from QObject to dispose of the QOject classe's services.
 */
class GameState    // TODO : add methods pause(), resume()
{
protected:
    GraphicsScene * m_scene;
public:
    /**
     * @brief Manage events received from the game state's own scene.
     */
    virtual void manageEvents(QKeyEvent *ev) = 0;
    virtual void clear() = 0;
    /**
     * @brief Getter for the scene of this intsance's game state.
     * @return The scene of the game state.
     */
    virtual GraphicsScene * getScene();
protected:
    /**
     * @brief Constructor.
     */
    GameState();
    /**
     * @brief Destructor.
     */
    virtual ~GameState();
    /**
     * @brief Update the current game state, according to the managed events.
     */
    virtual void update() = 0;
};

inline GameState::GameState()
{
}

inline GameState::~GameState()
{
}

inline GraphicsScene*
GameState :: getScene()
{
    return m_scene;
}

#endif // GAMESTATE_H
