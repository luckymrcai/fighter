#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

#include "my_item.h"
class Enemy_Bullet: public My_item
{
public:
    Enemy_Bullet(const QString & filename,QGraphicsScene *scene);
    void advance(int phase);



};

#endif // ENEMY_BULLET_H
