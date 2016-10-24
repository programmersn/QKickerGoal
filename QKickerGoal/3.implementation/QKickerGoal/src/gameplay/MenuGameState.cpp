/**
 * @file MenuGameState.cpp
 * @author Nouaim Souiki
 * @date 2014 November 25th
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */
#include <QKeyEvent>
#include "MenuGameState.h"
#include "../engine/graphicsengine/GraphicsScene.h"
#include "../engine/graphicsengine/GraphicsEntity.h"

MenuGameState *
MenuGameState :: instance = nullptr;

QMap<QString, QPixmap*>
MenuGameState :: pixmaps =
{
};

MenuGameState :: MenuGameState()
{
    MenuGameState::loadPixmaps();
    m_scene = new GraphicsScene(new GraphicsEntity(MenuGameState::pixmaps.value(
                                                       "background")),
                                this);
}

MenuGameState :: ~MenuGameState()
{
    std::cout << "**MenuGameState** : shutodown ...";
    this->clear();
    if (MenuGameState::instance != nullptr) {
        std::cout << "clear() : Destroying unique instance pgs ...";
        delete MenuGameState::instance;
        MenuGameState::instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance : pgs doesn't exist" << std::cout;
}

MenuGameState*
MenuGameState :: getInstance()
{
    if (MenuGameState::instance == nullptr)
        MenuGameState::instance = new MenuGameState();
    return MenuGameState::instance;
}

void
MenuGameState :: clear()
{
   // m_scene->clear();
}

void
MenuGameState::loadPixmaps()
{
    MenuGameState::pixmaps.insert("background", new QPixmap((":datas/images/"
                                                             "menugamestate/"
                                                             "menu-background"
                                                             ".jpg")));
}

void
MenuGameState :: manageEvents(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_G) {
        Kernel::getInstance()->popState();
        return;
    }
}

void
MenuGameState :: update()
{

}
