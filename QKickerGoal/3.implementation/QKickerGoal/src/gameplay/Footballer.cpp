#include <iostream>
#include <QTimeLine>
#include "Footballer.h"
#include "Avatar.h"
#include "Field.h"
#include "Ball.h"
#include "Team.h"

QMap<QString, QPixmap*>
Footballer :: pixmaps =
{
};

bool
Footballer :: pixmapsLoaded = false;

Footballer*
Footballer :: ballOwner = nullptr;

Footballer :: Footballer(Field * field, Ball * ball, Team * team,
                         bool hasKickOff)
    : MovableEntity(field->boundingRect()),
      m_field(field),
      m_ball(ball),
      m_team(team),
      m_hasKickOff(hasKickOff)
{
    if ( ! Footballer::pixmapsLoaded) {
        this->loadPixmaps();
        Footballer::pixmapsLoaded = true;
    }
}

Footballer :: ~Footballer()
{
    Footballer::pixmaps.clear();
}

void
Footballer :: loadPixmaps()
{
    std::cout << typeid(*this).name() << " loading datas ..." << std::endl;
    Footballer::pixmaps.insert(QString("Up_red"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/red/avatar/up.png"));
    Footballer::pixmaps.insert(QString("Right_red"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                          "footballer/red/"
                                           "avatar/right.png"));
    Footballer::pixmaps.insert(QString("Left_red"),
                               new QPixmap(":/datas/images/playinggamestate/""footballer/red/"
                                           "avatar/left.png"));
    Footballer::pixmaps.insert(QString("Down_red"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "avatar/down.png"));
    Footballer::pixmaps.insert(QString("RightUp_red"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "avatar/rightup.png"));
    Footballer::pixmaps.insert(QString("RightDown_red"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "avatar/rightdown.png"));
    Footballer::pixmaps.insert(QString("LeftUp_red"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "avatar/leftup.png"));
    Footballer::pixmaps.insert(QString("LeftDown_red"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "avatar/leftdown.png"));
    Footballer::pixmaps.insert(QString("Up_blue"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "avatar/up.png"));
    Footballer::pixmaps.insert(QString("Right_blue"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/blue/avatar/"
                                           "right.png"));
    Footballer::pixmaps.insert(QString("Left_blue"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/blue/avatar/left.png"));
    Footballer::pixmaps.insert(QString("Down_blue"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/blue/avatar/down.png"));
    Footballer::pixmaps.insert(QString("RightUp_blue"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/blue/avatar/"
                                           "rightup.png"));
    Footballer::pixmaps.insert(QString("RightDown_blue"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/blue/avatar/"
                                           "rightdown.png"));
    Footballer::pixmaps.insert(QString("LeftUp_blue"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/blue/avatar/"
                                           "leftup.png"));
    Footballer::pixmaps.insert(QString("LeftDown_blue"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "avatar/leftdown.png"));
    Footballer::pixmaps.insert(QString("Up_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/red/goalkeeper/up.png"));
    Footballer::pixmaps.insert(QString("Right_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/red/goalkeeper"
                                           "/right.png"));
    Footballer::pixmaps.insert(QString("Left_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/red/goalkeeper/"
                                           "left.png"));
    Footballer::pixmaps.insert(QString("Down_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/red/goalkeeper/"
                                           "down.png"));
    Footballer::pixmaps.insert(QString("RightUp_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/"
                                           "footballer/red/goalkeeper/rightup.png"));
    Footballer::pixmaps.insert(QString("RightDown_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "goalkeeper/rightdown.png"));
    Footballer::pixmaps.insert(QString("LeftUp_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "goalkeeper/leftup.png"));
    Footballer::pixmaps.insert(QString("LeftDown_red_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/red/"
                                           "goalkeeper/leftdown.png"));
    Footballer::pixmaps.insert(QString("Up_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/up.png"));
    Footballer::pixmaps.insert(QString("Right_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/right.png"));
    Footballer::pixmaps.insert(QString("Left_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/left.png"));
    Footballer::pixmaps.insert(QString("Down_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/down.png"));
    Footballer::pixmaps.insert(QString("RightUp_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/rightup.png"));
    Footballer::pixmaps.insert(QString("RightDown_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/rightdown.png"));
    Footballer::pixmaps.insert(QString("LeftUp_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/leftup.png"));
    Footballer::pixmaps.insert(QString("LeftDown_blue_goal"),
                               new QPixmap(":/datas/images/playinggamestate/footballer/blue/"
                                           "goalkeeper/leftdown.png"));
}

QString
Footballer :: makeAppropriatePixmapKey (Direction dir)
{
    QString key;

    /* Select pixmap according to the current direction of the footballer ...*/
    switch (dir) {
    case     Direction::RightUp:   key = QString("RightUp");   break;
    case     Direction::RightDown: key = QString("RightDown"); break;
    case     Direction::LeftUp:    key = QString("LeftUp");    break;
    case     Direction::LeftDown:  key = QString("LeftDown");  break;
    case     Direction::Right:     key = QString("Right");     break;
    case     Direction::Up:        key = QString("Up");        break;
    case     Direction::Left:      key = QString("Left");      break;
    case     Direction::Down:      key = QString("Down");      break;
    case     Direction::None:
    default: return QString();
    }

    /* ... and according to its team's color */
    if (m_team->getColor() == Team::Color::Red)
        key.append("_red");
    else if (m_team->getColor() == Team::Color::Blue)
        key.append("_blue");

    return key;
}

void
Footballer :: setAppropriatePixmap(Direction dir)
{
    QString key = this->makeAppropriatePixmapKey(dir);
    this->setPixmap(*Footballer::pixmaps.value(key));
}

QPointF
Footballer :: move(Direction dir)
{
    this->setAppropriatePixmap(dir);
    /* Only the Footballer know how to move the ball of its feet : it does it */
    if (this->isBallOwner()) {
        this->replaceBallFrontOfFeet(dir);
        m_ball->enableRotation();
        //m_ball->move(m_direction);
        return MovableEntity::move(dir);
    }
    else {
        QPointF dest = MovableEntity::move(dir);
        if (this->collidesWith(m_ball)) {
            Footballer::ballOwner = this;
            m_ball->enableRotation();
        }
        return dest;
    }
    return this->pos();
}

void
Footballer :: replaceBallFrontOfFeet(Direction dir)
{
    QPointF newPos;
    qreal ballW = m_ball->getBoundingRectSize().width();
    qreal ballH = m_ball->getBoundingRectSize().height();
    switch (dir) {
    case Direction::Right:
        newPos = QPointF(this->x()+this->getBoundingRectSize().width(),
                         (this->y()+this->y()+
                          this->getBoundingRectSize().height())/2-ballH/2);
        break;
    case Direction::Up:
        newPos = QPointF((this->x()+this->x()+
                          this->getBoundingRectSize().width())/2-ballW/2,
                         this->y()-ballH);
        break;
    case Direction::Left:
        newPos = QPointF(this->x()-ballW,
                         (this->y()+this->y()+
                          this->getBoundingRectSize().height())/2-ballH/2);
        break;
    case Direction::Down:
        newPos = QPointF((this->x()+this->x()+
                          this->getBoundingRectSize().width())/2-ballW/2,
                         this->y()+this->getBoundingRectSize().height());
        break;
    case Direction::RightUp:
        newPos = QPointF(this->x()+this->getBoundingRectSize().width()+ballW,
                         this->y()+ballH);
        break;
    case Direction::RightDown:
        newPos = QPointF(this->x()+this->getBoundingRectSize().width(),
                         this->y()+this->getBoundingRectSize().height());
        break;
    case Direction::LeftUp:
        newPos = QPointF(this->x()-ballW/2, this->y()-ballH/2);
        break;
    case Direction::LeftDown:
        newPos = QPointF(this->x()-ballW,
                         this->y()+this->getBoundingRectSize().height());
        break;
    case Direction::None:
    default: return;
    }
    m_ball->setPosition(newPos);
}

bool
Footballer :: pass()
{
 /*   QPointF oldpos = m_ball->pos();
    QPointF partPos = this->getPartner()->pos();
    QPointf newPos = m_ball->move();
    return false;*/
}

bool
Footballer :: shoot()   //! @todo Factorize this method with Footballer::pass()
{
    return false;
}

bool
Footballer :: isBallOwner()
{
    return Footballer::ballOwner == this;
}

Footballer *
Footballer :: getBallOwner()
{
    return Footballer::ballOwner;
}

bool
Footballer :: belongsTo(Team *team)
{
    return team == m_team;
}

Avatar*
Footballer :: getPartner()
{
    if (this != m_team->getAvatar1())
        return m_team->getAvatar1();
    return m_team->getAvatar2();
}
