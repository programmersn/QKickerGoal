/**
 * @file Field.h
 * @author Nouaim Souiki
 * Last modification : 2014, November 19th, by : Nouaim Souiki
 */

#ifndef FIELD_H
#define FIELD_H

#include "../engine/graphicsengine/GraphicsEntity.h"

/**
 * @author Nouaim Souiki
 * @brief Represent a football field in the game.
 * A field is a simple graphics entity ...
 * @todo Add a timeday mode Mode { Day, Night } and load the following
 * pixmap.
 */
class Field : public GraphicsEntity
{
public :
    enum class Half { Right, Left };
private:
    static QMap<QString, QPixmap*> pixmaps;
    QSizeF m_size;

public:
    Field();
    virtual ~Field();
    QSizeF getSize() const;
    void loadPixmaps();
};

#endif // FIELD_H
