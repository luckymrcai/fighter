#include "my_item_bullet.h"
#include <QDebug>

My_item_bullet::My_item_bullet(const QString & filename,QGraphicsScene *scene)
      :My_item(filename,scene,MY_BULLETE_TYPE)
{
//    qDebug()<<"new My_item_bullet";
    this->strength=1;
}
