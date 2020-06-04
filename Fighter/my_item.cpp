#include "my_item.h"

My_item::My_item(const QString & filename,QGraphicsScene *scene,int type)
{
    this->pixmap=filename;
    this->scene=scene;
    scene->addItem(this);
    this->m_type=type;
}

My_item::My_item(const QString & filename,QGraphicsScene *scene,int type,int blood,int score)
{
    this->pixmap=filename;
    this->scene=scene;
    scene->addItem(this);
    this->m_type=type;
    this->Blood=blood;
    this->Score=score;
}

QRectF My_item::boundingRect() const
{
    return QRectF(QPointF(0,0),this->pixmap.size());
}

void My_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,this->pixmap);
}


