#ifndef ENEMY_FISH_H
#define ENEMY_FISH_H

#include "my_item.h"
#include "enemy_bullet.h"

class Enemy_Fish : public My_item
{
public:
    Enemy_Fish(const QString & filename,QGraphicsScene *scene);
    void advance(int phase);

};

#endif // ENERMY_FISH_H
