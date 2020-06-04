#ifndef MY_ITEM_BULLET_H
#define MY_ITEM_BULLET_H
#include <QString>
#include <QGraphicsScene>
#include "my_item.h"

class My_item_bullet : public My_item
{
public:
    My_item_bullet(const QString & filename,QGraphicsScene *scene);

    int strength;


signals:

public slots:

};

#endif // MY_ITEM_BULLET_H
