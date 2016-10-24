/**
 * @file GraphicsEngine.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification :
 * - 2014, November 24th, by : Nouaim Souiki (Changed destructor access right to
 *   public).
 */

#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "../Engine.h"
#include "../../patterns/Singleton.h"

class Kernel;
class GameState;
class QGraphicsView;

/**
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * @brief The GraphicsEngine class
 */
class GraphicsEngine final:
        public Engine//,
       /* public Singleton<GraphicsEngine>*/
{
  //  friend class Singleton<GraphicsEngine>;
private:
    static GraphicsEngine * instance;
    GameState * m_currentGameState;
    QGraphicsView * m_view;

public :
    virtual ~GraphicsEngine();
    static GraphicsEngine * getInstance();
    virtual void run() override;
    virtual void update() override;
    virtual void clear() override;
    void draw();
protected:
    GraphicsEngine();
};


#endif // GRAPHICSENGINE_H
