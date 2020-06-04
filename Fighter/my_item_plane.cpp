#include "my_item_plane.h"
#include <QDebug>

My_item_plane::My_item_plane(const QString & filename,QGraphicsScene *scene)
    :My_item(filename,scene,MY_PLANE_TYPE)
{
//    qDebug()<<"new my_item_plane";
    this->Blood=5;
}

//void My_item_plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->drawPixmap(0,0,this->pixmap);
//}

//QRectF My_item_plane::boundingRect() const
//{
//    return QRectF(QPointF(0,0),this->pixmap.size());
//}
