/**
 * @file GraphicsScene.cpp
 * @author Imane
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */

#include <iostream>
#include <cassert>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "GraphicsScene.h"
#include "../Kernel.h"
#include "../gamestates/GameState.h"
#include "GraphicsEntity.h"
#include "../../gameplay/Avatar.h"
#include "../../gameplay/Team.h"
#include "../../gameplay/GoalKeeper.h"

GraphicsScene :: GraphicsScene(GraphicsEntity * background, GameState *state)
    : QGraphicsScene(), m_background(background), m_currentGameState(state)
{
    this->add(background);
    this->startTimer(25);
    std::cout << "--GraphicsScene::GraphicsScene() done--" << std::endl;
}

GraphicsScene :: ~GraphicsScene()
{
    std::cout << "--GraphicsScene::~GraphicsEntity() done--" << std::endl;
    this->clear();
}

void
GraphicsScene :: keyPressEvent(QKeyEvent *ev)
{
    m_currentGameState->manageEvents(ev);
    std::cout << "**GraphicsScene** : \"KeyPress\" event delegated to the "
                 "current game state ... " << std::endl;

}

void
GraphicsScene :: keyReleaseEvent(QKeyEvent *ev)
{
    m_currentGameState->manageEvents(ev);
    std::cout << "**GraphicsScene** : \"KeyRelease\" event delegated to the "
                 "current game state ... " << std::endl;
}

void
GraphicsScene :: timerEvent(QTimerEvent *)
{
  //  Kernel::getInstance()->notify();
}

void
GraphicsScene :: add(GraphicsEntity *entity)
{
    this->addItem(entity);
}

void
GraphicsScene :: add(Team * team)
{
    this->add(team->getAvatar1());
    this->add(team->getAvatar2());
    this->add(team->getGoalKeeper());
}

