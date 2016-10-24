/**
 * @file IntroGameState.h
 * @author Nouaim Souiki
 * @date 2014, November 14th
 * Last modification : 2014, November 24th, by : Nouaim Souiki
 */
#include <iostream>
#include <QKeyEvent>
#include "IntroGameState.h"
#include "PlayingGameState.h"
#include "../engine/Kernel.h"
#include "../engine/graphicsengine/GraphicsScene.h"
#include "../engine/graphicsengine/GraphicsEntity.h"

IntroGameState*
IntroGameState :: instance = nullptr;

QMap<QString, QPixmap*>
IntroGameState :: pixmaps = {

};


IntroGameState :: IntroGameState()
    //: Singleton<IntroGameState>()
{
    IntroGameState::loadPixmaps();

    m_scene = new GraphicsScene(new GraphicsEntity(IntroGameState::pixmaps.value
                                                   ("background")),
                                this);
}

IntroGameState :: ~IntroGameState()
{
    std::cout << "**IntroGameState** : releasing datas for shutdown ... "
                 << std::endl;

    std::cout << "**IntroGameState** : shutodown ...";
    this->clear();
    if (IntroGameState::instance != nullptr) {
        std::cout << "clear() : Destroying unique instance pgs ...";
        delete IntroGameState::instance;
        IntroGameState::instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance : pgs doesn't exist" << std::cout;
}

IntroGameState*
IntroGameState :: getInstance()
{
    if (IntroGameState::instance == nullptr)
        IntroGameState::instance = new IntroGameState();
    return IntroGameState::instance;
}

void
IntroGameState :: clear()
{
    m_scene->clear();
}

void
IntroGameState :: manageEvents(QKeyEvent *ev)
{
    std::cout << "**IntroGameState** : \"KeyPress\" event received"
              << std::endl;
    static int n = 0;

    if(ev->key() == Qt::Key_Escape)
        return;

//    if (n==0)
        Kernel::getInstance()->pushState(PlayingGameState::getInstance());

    n++;
}

void
IntroGameState::loadPixmaps()
{
    IntroGameState::pixmaps.insert("background", new QPixmap((":datas/images/"
                                                             "introgamestate/"
                                                             "intro-background"
                                                             ".jpg")));
}

void
IntroGameState :: update()
{

}

