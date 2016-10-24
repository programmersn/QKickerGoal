/**
 * @file GraphicsScene.h
 * @author Nouaim Souiki
 * @date 2014, November 11th
 * Last modification : 2014, November 11th, by : Nouaim Souiki
 */

#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QtWidgets/QGraphicsScene>


class GameState;
class GraphicsEntity;
class Team;

/**
 * @author Nouaim Souiki
 * @date 2014, November 11th
 * @brief Build the scene of the current state game.
 * Provider (for ist own game state) of methods to add items on the scene and
 * handle events from it.
 */
class GraphicsScene final: public QGraphicsScene
{
private:
    /**
     * @brief Pointer to the entity which represent the background of the
     * scene.
     */
    GraphicsEntity * m_background;
    /**
     * @brief Pointer to the current game state.
     */
    GameState * m_currentGameState;

public:
    /**
     * @brief Constructor
     * @param background The background to set in the scene
     * @param currenGameState The current game state, which instanciated this
     * scene.
     */
    GraphicsScene(GraphicsEntity * background, GameState *currentGameState);
    /**
     * @brief Destructor
     */
    virtual ~GraphicsScene();
    /**
     * @brief
     * @param entity
     */
    void add (GraphicsEntity * entity);
    /**
     * @brief Overload of add(GraphicsEntity*).
     * @param team
     */
    void add (Team * team);

protected:
    /**
      * @brief Reimplement QGraphicsScene::keyPressEvent()
      * @param ev The event handled
      * This method only handle the event of the current scene, and delegate
      * <I>managing</I> event to the current game state.
      * @see GameState::managingEvents()
      */
    virtual void keyPressEvent(QKeyEvent *ev) override;
    /**
      * @brief Reimplement QGraphicsScene::keyReleaseEvent()
      * @param ev The event handled
      * This method only handle the event of the current scene, and delegate
      * <I>managing</I> event to the current game state.
      * @see GameState::managingEvents()
      */
    virtual void keyReleaseEvent(QKeyEvent *ev) override;
    void  timerEvent(QTimerEvent *);
};

#endif // GRAPHICSSCENE_H

