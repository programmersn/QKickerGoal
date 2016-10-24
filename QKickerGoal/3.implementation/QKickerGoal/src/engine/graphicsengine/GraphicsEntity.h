/**
 * @file GraphicsEntity.h
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * Last modification : 2014, November 13th, by : Nouaim Souiki
 */

#ifndef GRAPHICSENTITY_H
#define GRAPHICSENTITY_H

#include <QGraphicsPixmapItem>

/**
 * @author Nouaim Souiki
 * @date 2014, November 08th
 * @brief The GraphicsEntity class represent a set of pixel drawable on a
 * game state's scene.
 */
class GraphicsEntity :
        public QObject,
        public QGraphicsPixmapItem
{
private:
    QPixmap * m_entityPixmap;

public:
    GraphicsEntity();
    GraphicsEntity(QPixmap * entityPixmap);
    virtual ~GraphicsEntity();
    QSizeF getBoundingRectSize();
};

#endif // GRAPHICSENTITY_H
