/**
 * @file MenuGameState.cpp
 * @author Nouaim Souiki
 * @date 2014 November 25th
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */
#ifndef MENUGAMESTATE_H
#define MENUGAMESTATE_H

#include <QTimer>
#include "../engine/gamestates/GameState.h"
#include "../patterns/Singleton.h"


/**
 * @author Nouaim Souiki
 * @date 2014 November 25th
 * @brief The state which represent the menu of the game
 */
class MenuGameState :
        public GameState//,
    //    public Singleton<MenuGameState>
{
  //  friend class Singleton<MenuGameState>;
private :
    static MenuGameState * instance;
    static QMap<QString, QPixmap*> pixmaps;
    QVector<GraphicsEntity*> m_choices;


public:
    virtual ~MenuGameState();
    static MenuGameState* getInstance();
    virtual void manageEvents(QKeyEvent *ev) override;
    virtual void clear() override;
private :
    MenuGameState();
    virtual void update() override;
    static void loadPixmaps();
};

#endif // MENUGAMESTATE_H
