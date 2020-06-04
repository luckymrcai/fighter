#ifndef MY_ITEM_PLANE_H
#define MY_ITEM_PLANE_H

#include "my_item.h"

class My_item_plane:public My_item
{
public:
    My_item_plane(const QString & filename,QGraphicsScene *scene);
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    QRectF boundingRect() const;

};

#endif // MY_ITEM_PLANE_H
