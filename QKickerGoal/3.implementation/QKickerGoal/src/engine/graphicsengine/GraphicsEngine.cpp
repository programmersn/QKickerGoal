/**
* @file GraphicsEngine.cpp
* @author Nouaim Souiki
* Last modification : 2014, November 17th, by : Nouaim Souiki
*/

#include <cassert>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QKeyEvent>
#include <QGLWidget>
#include "GraphicsEngine.h"
#include "GraphicsScene.h"
#include "../Kernel.h"
#include "../gamestates/GameState.h"
#include "GraphicsEntity.h"

GraphicsEngine *
GraphicsEngine :: instance = nullptr;

GraphicsEngine :: GraphicsEngine()
    : //Singleton<GraphicsEngine>(),
      m_currentGameState(nullptr)
{
    m_view = new QGraphicsView();
    //  QMainWindow win();
    /*   win.setWindowState (Qt::WindowFullScreen);
                              win.setVisible(true);*/
    /* win.setCentralWidget(m_view); */
    //    m_view->setBackgroundBrush(Qt::blue);
    m_view->setRenderHints(QPainter::Antialiasing |
                           QPainter::SmoothPixmapTransform);


    /*#ifndef QT_NO_OPENGL
    m_view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
#endif*/

    /*   m_currentGameState = Kernel::getInstance()->getCurrentGameState(); */
    std::cout << "--GraphicsEngine::GraphicsEngine() done.--" << std::endl;
}

GraphicsEngine :: ~GraphicsEngine()
{
    std::cout << "**GraphicsEngine** : releasing datas for shutdown ... "
              << std::endl;

    std::cout << "**GraphicsEngine** : shutodown ...";
    this->clear();
    if (GraphicsEngine::instance != nullptr) {
        std::cout << "clear() : Destroying unique instance ge ...";
        delete GraphicsEngine::instance;
        GraphicsEngine::instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance : ge doesn't exist" << std::cout;
}

GraphicsEngine*
GraphicsEngine :: getInstance()
{
    if (GraphicsEngine::instance == nullptr)
        GraphicsEngine::instance = new GraphicsEngine();
    return GraphicsEngine::instance;
}


void
GraphicsEngine :: run()
{
    std::cout << "**GraphicsEngine** : running started." << std::endl;
    this->draw();
}

void
GraphicsEngine :: clear()
{
       delete m_view;
    if (GraphicsEngine::instance != nullptr) {
        std::cout << "clear() : Destroying unique instance ge ...";
        delete GraphicsEngine::instance;
        GraphicsEngine::instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance : ge doesn't exist" << std::cout;
}

void
GraphicsEngine :: update()
{
    std::cout << "**GraphcisEngine** : notification received from core-kernel."
              << std::endl;

    // Reload the current game state if changed.
    if (m_currentGameState != Kernel::getInstance()->getCurrentGameState()) {
        std::cout << "**GraphcisEngine** : getting instance of the new game state "
                  << "\"";

        m_currentGameState = Kernel::getInstance()->getCurrentGameState();

    /*    std::cout << typeid(*m_currentGameState).name() << "\" ... Got."
                  << std::endl;
        printf ("#### currentState: %s %s#####\n", typeid(m_currentGameState).name(), m_currentGameState==nullptr? "null":"notnull");*/
    /*    m_view->setScene(
                    m_currentGameState->getScene());*/
        m_view->setScene(
                    m_currentGameState->getScene());

        m_view->scale(0.9,0.7);
    }
    m_view->scene()->update();
    m_view->show();

}

void
GraphicsEngine :: draw()
{
    // TODO
    // set m_view as attribut of currentGameState
    // then get it from a GameState's getter, and draw here the scene.
    std::cout << "**GraphicsEngine** : drawing current game state's scene ... ";

 //   m_view->fitInView(m_view->sceneRect(), Qt::KeepAspectRatio);


    // Set the scene of the current game state
}

