#include "widget_game.h"
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

Widget_Game::Widget_Game(MyWidget *parent)
    : MyWidget(parent)
{
    //背景在窗口中绘制

    this->parent=parent;
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //滚动背景1
    QLabel *label1=new QLabel(this);
    label1->setStyleSheet("QLabel{border-image:url(img/image/map/bg_hei_0.jpg);}");

    //滚动背景2
    QLabel *label2=new QLabel(this);
    label2->setStyleSheet("QLabel{border-image:url(img/image/map/bg_hei_0.jpg);}");

    //滚动背景3
    QLabel *label3=new QLabel(this);
    label3->setStyleSheet("QLabel{border-image:url(img/image/map/bg_hei_0.jpg);}");

    //动画类
    QPropertyAnimation *Animation1=new QPropertyAnimation(label1,"geometry",this);
    Animation1->setKeyValueAt(0,QRect(0,0,640,950));//设置图片初始化位置
    Animation1->setKeyValueAt(1,QRect(0,1900,640,950));//设置图片末位置
    Animation1->setDuration(20000);//设置初末位置的时间间隔

    QPropertyAnimation *Animation2=new QPropertyAnimation(label2,"geometry",this);
    Animation2->setKeyValueAt(0,QRect(0,-950,640,950));
    Animation2->setKeyValueAt(1,QRect(0,950,640,950));
    Animation2->setDuration(20000);

    QPropertyAnimation *Animation3=new QPropertyAnimation(label3,"geometry",this);
    Animation3->setKeyValueAt(0,QRect(0,-1900,640,950));
    Animation3->setKeyValueAt(1,QRect(0,0,640,950));
    Animation3->setDuration(20000);

    //动画类组
    QParallelAnimationGroup *group=new QParallelAnimationGroup;
    group->addAnimation(Animation1);
    group->addAnimation(Animation2);
    group->addAnimation(Animation3);
    group->setLoopCount(-1);//无限循环
    group->start();//启动动画组


    GameView=new Gameview(this);

}


