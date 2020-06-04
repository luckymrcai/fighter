#include "enemy_bullet.h"

Enemy_Bullet::Enemy_Bullet(const QString & filename,QGraphicsScene *scene)
     :My_item(filename,scene,ENEMY_BULLET)
{

}
void Enemy_Bullet::advance(int phase)
{
    this->moveBy(0,5);
    if(this->pos().x()<-10||this->pos().x()>700||this->pos().y()>1000)
    {
        delete this;
    }
}
