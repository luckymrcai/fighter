#include "enemy_fish.h"
#include <QDebug>
Enemy_Fish::Enemy_Fish(const QString & filename,QGraphicsScene *scene)
    :My_item(filename,scene,ENEMY_FISH,ENEMY_FISH_BLOOD,ENEMY_FISH_SCORE)
{

}

void Enemy_Fish::advance(int phase)
{
    static int speed=0;
    speed++;
    this->moveBy(0,1);
    if(speed%70==0)
    {
        Enemy_Bullet *enemy_bullet=new Enemy_Bullet("img/image/bullet/bullet-01-c.png",this->scene);
        enemy_bullet->setPos(this->x(),this->y());
    }
    if(this->pos().x()<-100||this->pos().x()>700||this->pos().y()>1000)
    {
        delete this;
    }

}
