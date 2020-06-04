#include "widget_game.h"
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

Widget_Game::Widget_Game(MyWidget *parent)
    : MyWidget(parent)
{
    //�����ڴ����л���

    this->parent=parent;
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //��������1
    QLabel *label1=new QLabel(this);
    label1->setStyleSheet("QLabel{border-image:url(img/image/map/bg_hei_0.jpg);}");

    //��������2
    QLabel *label2=new QLabel(this);
    label2->setStyleSheet("QLabel{border-image:url(img/image/map/bg_hei_0.jpg);}");

    //��������3
    QLabel *label3=new QLabel(this);
    label3->setStyleSheet("QLabel{border-image:url(img/image/map/bg_hei_0.jpg);}");

    //������
    QPropertyAnimation *Animation1=new QPropertyAnimation(label1,"geometry",this);
    Animation1->setKeyValueAt(0,QRect(0,0,640,950));//����ͼƬ��ʼ��λ��
    Animation1->setKeyValueAt(1,QRect(0,1900,640,950));//����ͼƬĩλ��
    Animation1->setDuration(20000);//���ó�ĩλ�õ�ʱ����

    QPropertyAnimation *Animation2=new QPropertyAnimation(label2,"geometry",this);
    Animation2->setKeyValueAt(0,QRect(0,-950,640,950));
    Animation2->setKeyValueAt(1,QRect(0,950,640,950));
    Animation2->setDuration(20000);

    QPropertyAnimation *Animation3=new QPropertyAnimation(label3,"geometry",this);
    Animation3->setKeyValueAt(0,QRect(0,-1900,640,950));
    Animation3->setKeyValueAt(1,QRect(0,0,640,950));
    Animation3->setDuration(20000);

    //��������
    QParallelAnimationGroup *group=new QParallelAnimationGroup;
    group->addAnimation(Animation1);
    group->addAnimation(Animation2);
    group->addAnimation(Animation3);
    group->setLoopCount(-1);//����ѭ��
    group->start();//����������


    GameView=new Gameview(this);

}


