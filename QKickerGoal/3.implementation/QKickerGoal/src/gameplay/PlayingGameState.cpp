/**
 * @file PlayingGameState.cpp
 * @author Nouaim Souiki
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */
#include <iostream>
#include <QKeyEvent>
#include "PlayingGameState.h"
#include "MenuGameState.h"
#include "../engine/graphicsengine/GraphicsScene.h"
#include "../engine/graphicsengine/GraphicsEntity.h"
#include "Field.h"
#include "Ball.h"
#include "Footballer.h"
#include "Avatar.h"
#include "Team.h"

PlayingGameState *
PlayingGameState :: instance = nullptr;

PlayingGameState :: PlayingGameState()
{
    this->initKeys();

    m_field = new Field();
    m_ball = new Ball(m_field);
    m_leftTeam = new Team(m_field, m_ball, Field::Half::Left,
                          Team::Color::Red, true);
    m_rightTeam = new Team(m_field, m_ball, Field::Half::Right,
                           Team::Color::Blue);

    m_scene = new GraphicsScene(m_field, this);
    m_scene->add(m_ball);
    m_scene->add(m_leftTeam);
    m_scene->add(m_rightTeam);

    this->startTimer(25);
    std::cout << "--PlayingGameState::PlayingGameState() done--" << std::endl;
}


PlayingGameState :: ~PlayingGameState()
{
    std::cout << "**PlayingGameState** : releasing datas for shutdown ... "
                 << std::endl;

    std::cout << "**PlayingGameState** : shutodown ...";
    this->clear();

    if (PlayingGameState::instance != nullptr) {
        std::cout << "clear() : Destroying unique instance pgs ...";
        delete PlayingGameState::instance;
        PlayingGameState::instance = nullptr;
        std::cout << " Done" << std::endl;
    }
    else std::cout << "Cannot destroy unique instance : pgs doesn't exist" << std::cout;
}

PlayingGameState*
PlayingGameState :: getInstance()
{
    if (PlayingGameState::instance == nullptr)
        PlayingGameState::instance = new PlayingGameState();
    return PlayingGameState::instance;
}

void
PlayingGameState :: clear()
{

    m_scene->clear();
}

void
PlayingGameState :: initKeys()
{
    m_rightTeamKey.up    = false;
    m_rightTeamKey.right = false;
    m_rightTeamKey.left  = false;
    m_rightTeamKey.down  = false;
    m_rightTeamKey.pass  = false;
    m_rightTeamKey.shoot = false;
    m_rightTeamKey.swap  = false;

    m_leftTeamKey.up    = false;
    m_leftTeamKey.right = false;
    m_leftTeamKey.left  = false;
    m_leftTeamKey.down  = false;
    m_leftTeamKey.pass  = false;
    m_leftTeamKey.shoot = false;
    m_leftTeamKey.swap  = false;
}

void
PlayingGameState :: manageEvents(QKeyEvent *ev)
{
    std::cout << "**PlayingGameState** : managing \"KeyPressed\" event ... "
              << std::endl;

    if (ev->key() == Qt::Key_Escape) {
       // this->clear();
        Kernel::getInstance()->pushState(MenuGameState::getInstance());
        return;
    }
    else if (ev->type() == QEvent::Type::KeyPress) {
        this->setKeysAs(ev, true);
    }
    else if (ev->type() == QEvent::Type::KeyRelease) {
        this->setKeysAs(ev, false);
    }
}

void
PlayingGameState :: reinit()
{
    m_ball->reinit();
    m_leftTeam->reinit();
    m_rightTeam->reinit();
}

void
PlayingGameState :: setKeysAs(QKeyEvent * ev, bool activation)
{
    /* Right team actions */
    if (ev->key() == Qt::Key_Right) {
        m_rightTeamKey.right = activation;

    }
    else if (ev->key() == Qt::Key_Up) {
        m_rightTeamKey.up = activation;

    }
    else if (ev->key() == Qt::Key_Left) {
        m_rightTeamKey.left = activation;
    }
    else if (ev->key() == Qt::Key_Down) {
        m_rightTeamKey.down = activation;
    }
    else if (ev->key() ==  Qt::Key_M) {
        m_rightTeamKey.pass = activation;
    }
    else if (ev->key() == Qt::Key_L) {
        m_rightTeamKey.shoot = activation;
    }
    else if (ev->key() == Qt::Key_K) {
        m_rightTeamKey.swap = activation;
    }

    /* Left team event */
    else if (ev->key() == Qt::Key_D) {
        m_leftTeamKey.right = activation;
    }
    else if (ev->key() == Qt::Key_Z) {
        m_leftTeamKey.up = activation;
    }
    else if (ev->key() ==  Qt::Key_Q) {
        m_leftTeamKey.left = activation;
    }
    else if (ev->key() == Qt::Key_S) {
        m_leftTeamKey.down = activation;
    }
    else if (ev->key() == Qt::Key_R) {
        m_leftTeamKey.pass = activation;
    }
    else if (ev->key() ==  Qt::Key_T) {
        m_leftTeamKey.shoot = activation;
    }
    else if (ev->key() ==  Qt::Key_E) {
        m_leftTeamKey.swap = activation;
    }
}

void
PlayingGameState :: timerEvent (QTimerEvent*)
{
    this->update();
    Kernel::getInstance()->notify();
}

void
PlayingGameState :: update()
{
    this->update(m_rightTeam, m_rightTeamKey);
    this->update(m_leftTeam, m_leftTeamKey);

}

void
PlayingGameState :: update (Team * team, PlayingKeys teamKey)
{
    Footballer * focused = this->getFocused(team);
    if (focused == nullptr)
        return;

    /* Right team event */
    if (teamKey.right && teamKey.up)
        focused->move(MovableEntity::Direction::RightUp);
    else if (teamKey.right && teamKey.down)
        focused->move(MovableEntity::Direction::RightDown);
    else if (teamKey.left && teamKey.up)
        focused->move(MovableEntity::Direction::LeftUp);
    else if (teamKey.left && teamKey.down)
        focused->move(MovableEntity::Direction::LeftDown);
    else if (teamKey.right)
        focused->move(MovableEntity::Direction::Right);
    else if (teamKey.up)
        focused->move(MovableEntity::Direction::Up);
    else if (teamKey.left)
        focused->move(MovableEntity::Direction::Left);
    else if (teamKey.down)
        focused->move(MovableEntity::Direction::Down);

    if (teamKey.pass) {

    }
    if (teamKey.shoot) {

    }
    if (teamKey.swap) {
        this->swapFocus(team);
    }
}

void
PlayingGameState :: swapFocus(Team * team)
{
    if (team->getAvatar1()->hasFocus()) {
        team->getAvatar1()->unsetFocus();
        team->getAvatar2()->setFocus();
    }
    else if (team->getAvatar2()->hasFocus()) {
        team->getAvatar2()->unsetFocus();
        team->getAvatar1()->setFocus();
    }
}

Avatar*
PlayingGameState :: getFocused(Team * team)
{
    if (team->getAvatar1()->hasFocus())
        return team->getAvatar1();
    if (team->getAvatar2()->hasFocus())
        return team->getAvatar2();
    return nullptr;
}


