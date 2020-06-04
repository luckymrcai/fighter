#ifndef MY_ITEM_H
#define MY_ITEM_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>

//类型
#define MY_PLANE_TYPE 1
#define MY_BULLETE_TYPE 2
#define ENEMY_FISH 3
#define ENEMY_BLAST 4
#define ENEMY_BOSS 5
#define ENEMY_BULLET 6

//血量
#define ENEMY_FISH_BLOOD 3
#define ENEMY_BOSS_BLOOD 600

//分数
#define ENEMY_FISH_SCORE 21
#define ENEMY_BOSS_SCORE 311

class My_item:public QGraphicsItem
{
public:
    My_item(const QString & filename,QGraphicsScene *scene,int type);
    My_item(const QString & filename,QGraphicsScene *scene,int type,int blood,int score);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPixmap pixmap;
    QGraphicsScene *scene;
    int m_type;
    int Blood;
    int Score;

};

#endif // MY_ITEM_H
