/**
 * @file Ball.cpp
 * @author Nouaim Souiki
 * @date 2014, November 15th
 * Last modification : 2014, November 15th, by : Nouaim Souiki
*/
#include <iostream>
#include <QtGlobal>
#include <QDebug>
#include "Ball.h"
#include "Field.h"

QMap<QString, QPixmap*>
Ball :: pixmaps =
{
};

Ball :: Ball(Field * field)
    : MovableEntity(field->boundingRect()),
      m_field(field),
      m_rotation(false)
{
    this->loadPixmaps();
    this->setPixmap(*Ball::pixmaps.value("pos1"));
    m_initPosition = this->computeInitPosition();
    this->setPos(m_initPosition);

    this->startTimer(24);
}

Ball :: ~Ball()
{
    Ball::pixmaps.clear();
}

QPointF
Ball :: computeInitPosition()
{
    QSizeF fieldSize = m_field->getBoundingRectSize();

    return QPointF(fieldSize.width()/2-10, fieldSize.height()/2-10);
}

QPointF
Ball :: move(Direction dir)
{
    m_direction = dir;
    QPointF dest = MovableEntity::move(m_direction);
    return dest;
}

void
Ball :: loadPixmaps()
{
    Ball::pixmaps.insert("pos0", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos0.png"));
    Ball::pixmaps.insert("pos1", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos1.png"));
    Ball::pixmaps.insert("pos2", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos2.png"));
    Ball::pixmaps.insert("pos3", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos3.png"));
    Ball::pixmaps.insert("pos4", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos4.png"));
    Ball::pixmaps.insert("pos5", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos5.png"));
    Ball::pixmaps.insert("pos6", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos6.png"));
    Ball::pixmaps.insert("pos7", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos7.png"));
    Ball::pixmaps.insert("pos8", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos8.png"));
    Ball::pixmaps.insert("pos9", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos9.png"));
    Ball::pixmaps.insert("pos10", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos10.png"));
    Ball::pixmaps.insert("pos11", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos11.png"));
    Ball::pixmaps.insert("pos12", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos12.png"));
    Ball::pixmaps.insert("pos13", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos13.png"));
    Ball::pixmaps.insert("pos14", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos14.png"));
    Ball::pixmaps.insert("pos15", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos15.png"));
    Ball::pixmaps.insert("pos16", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos16.png"));
    Ball::pixmaps.insert("pos17", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos17.png"));
    Ball::pixmaps.insert("pos18", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos18.png"));
    Ball::pixmaps.insert("pos19", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos19.png"));
    Ball::pixmaps.insert("pos20", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos20.png"));
    Ball::pixmaps.insert("pos21", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos21.png"));
    Ball::pixmaps.insert("pos22", new QPixmap(":datas/images/playinggamestate/ball/"
                                             "ball_pos22.png"));
    Ball::pixmaps.insert("pos23", new QPixmap(":datas/images/playinggamestate/ball/"
                                              "ball_pos23.png"));

}

void
Ball :: timerEvent(QTimerEvent *)
{
    if (this->isMoving()) this->enableRotation();
    else this->disableRotation();
    if(m_rotation)
        this->rotate();

}

bool
Ball :: isMoving()
{
    static QPointF oldPos = this->pos();
    bool answ = false;

    if (oldPos != this->pos())
        answ = true;
    oldPos = this->pos();

    return answ;
}

void
Ball :: enableRotation()
{
    m_rotation = true;
}

void
Ball :: disableRotation()
{
    m_rotation = false;
}

bool
Ball :: rotate()
{
    static int i = 0;

    QString key(QString("pos").append(QString().setNum(i)));

    this->setPixmap(*pixmaps.value(key));
    i = (i+1)%Ball::pixmaps.size();
}
