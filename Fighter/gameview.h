#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QEvent>
#include <QTimer>
#include <QList>
#include "my_item_plane.h"
#include "my_item_bullet.h"
#include "enemy_fish.h"
#include "enemy_blast.h"
#include "enemy_boss.h"
#include "enemy_bullet.h"
#include "widget_score.h"
#include <phonon>
#include <QLabel>
#include <QPushButton>
class Gameview:public QGraphicsView
{
    Q_OBJECT
public:
    explicit Gameview(MyWidget *parent=0);
    bool key_left;
    bool key_right;
    bool key_up;
    bool key_down;
    bool FireFlag;//发射标志位
    bool FileFlagMouse;//鼠标发射标志位
    int CountDownFlag;//321标志位
    QLabel *ScoreLbl;//分数
    QLabel *BloodLbl;//血量
    QLabel *EnemyBloodLbl;//敌机血量
    QLabel *CountDownLbl;//倒计时
    QLabel *GuideLbl;//新手指引
    QLabel *PauseLbl;//暂停标签
    QLabel *GameOverLbl;//游戏结束
    QPushButton *PauseBtn;//暂停按钮
    QPushButton *ContinueBtn;//继续按钮
    QPushButton *QuitBtn;//退出按钮
    QPushButton *YesBtn;
    QTimer *time;
    QTimer *time1;//产生子弹的速度
    QTimer *time2;//子弹移动的速度
    QTimer *time3;//产生敌机小兵仔的速度
    QTimer *time4;//advance
    QTimer *time5;//321
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path path;
    MyWidget *parent;
    QGraphicsScene *pScene;//场景
    My_item_plane *item_plane;//图元
    QList<My_item_bullet *> my_bullte;//子弹链表
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void ShowScore();
    void SaveScore();
    void SetButtonStyleH(QPushButton *button, QString imgsrc, int CutSec);

public slots:
    void PauseBtnClick();
    void ContinueBtnClick();
    void QuitBtnClick();
    void YesBtnClick();
    void plane_move();
    void bullet_produce();
    void bullet_move();
    void enemy_fish_produce();
    void count_down();

};

#endif // GAMEVIEW_H
