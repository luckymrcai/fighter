#ifndef ENEMY_BOSS_H
#define ENEMY_BOSS_H

#include "my_item.h"
#include "QPainter"
#include "enemy_bullet.h"
#include <QtGui>
class Enemy_Boss: public My_item
{
public:
    Enemy_Boss(const QString & filename,QGraphicsScene *scene);
    void advance(int phase);

};

#endif // ENERMY_BOSS_H
