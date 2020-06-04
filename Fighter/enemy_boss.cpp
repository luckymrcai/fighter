#include "enemy_boss.h"
#include "QDebug"
Enemy_Boss::Enemy_Boss(const QString & filename,QGraphicsScene *scene)
    :My_item(filename,scene,ENEMY_BOSS,ENEMY_BOSS_BLOOD,ENEMY_BOSS_SCORE)
{
    this->setPos((640-this->pixmap.width())/2,20);
}

void Enemy_Boss::advance(int phase)
{
    static int MoveFlag=0;//移动标志物

    //向左移动
    if(MoveFlag==0)
    {
        this->moveBy(-0.5,0);
        if(mapToScene(0,0).x()<0)
        {
            MoveFlag=1;
        }
    }
    //向右移动
    if(MoveFlag==1)
    {
        this->moveBy(0.5,0);
        if(mapToScene(0,0).x()>640-this->pixmap.width())
        {
            MoveFlag=0;
        }
    }
    static int speed=0;
    speed++;
    if(speed%111==0)
    {
        for(int i=0;i<8;i++)
        {
            Enemy_Bullet *enemy_bullet3=new Enemy_Bullet("img/image/bullet/bullet-03.png",this->scene);
            enemy_bullet3->setPos(this->x()+10,this->y()+this->pixmap.height()-i*30);
            Enemy_Bullet *enemy_bullet4=new Enemy_Bullet("img/image/bullet/bullet-03.png",this->scene);
            enemy_bullet4->setPos(this->x()+180,this->y()+this->pixmap.height()-i*30);
            Enemy_Bullet *enemy_bullet5=new Enemy_Bullet("img/image/bullet/bullet-03.png",this->scene);
            enemy_bullet5->setPos(this->x()+360,this->y()+this->pixmap.height()-i*30);
        }

    }
    if(speed%252==0)
    {
        for(int i=0;i<2;i++)
        {
            Enemy_Bullet *enemy_bullet1=new Enemy_Bullet("img/image/bullet/bossbullet.png",this->scene);
            enemy_bullet1->setPos(this->x()+50,this->y()+this->pixmap.height()-100*i);
            Enemy_Bullet *enemy_bullet2=new Enemy_Bullet("img/image/bullet/bossbullet.png",this->scene);
            enemy_bullet2->setPos(this->x()+200,this->y()+this->pixmap.height()-100*i);
        }

    }
    if(speed%401==0)
    {
        for(int i=0;i<3;i++)
        {
            Enemy_Bullet *enemy_bullet6=new Enemy_Bullet("img/image/bullet/bullet-mini-boss05.png",this->scene);
            enemy_bullet6->setPos(this->x()+50,this->y()+this->pixmap.height()-i*80);
            Enemy_Bullet *enemy_bullet7=new Enemy_Bullet("img/image/bullet/bullet-mini-boss05.png",this->scene);
            enemy_bullet7->setPos(this->x()+200,this->y()+this->pixmap.height()-i*80);
            Enemy_Bullet *enemy_bullet8=new Enemy_Bullet("img/image/bullet/bullet-mini-boss05.png",this->scene);
            enemy_bullet8->setPos(this->x()+330,this->y()+this->pixmap.height()-i*80);
        }

    }
}





