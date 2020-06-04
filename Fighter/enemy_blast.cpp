#include "enemy_blast.h"

Enemy_Blast::Enemy_Blast(const QString & filename,QGraphicsScene *scene)
    :My_item(filename,scene,ENEMY_BLAST)
{

}

void Enemy_Blast::advance(int phase)
{
    static int i=0;
    i++;
    if(i%10==0)
    {
        this->hide();
        delete this;
    }
}
