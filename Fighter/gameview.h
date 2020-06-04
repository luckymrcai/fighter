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
    bool FireFlag;//�����־λ
    bool FileFlagMouse;//��귢���־λ
    int CountDownFlag;//321��־λ
    QLabel *ScoreLbl;//����
    QLabel *BloodLbl;//Ѫ��
    QLabel *EnemyBloodLbl;//�л�Ѫ��
    QLabel *CountDownLbl;//����ʱ
    QLabel *GuideLbl;//����ָ��
    QLabel *PauseLbl;//��ͣ��ǩ
    QLabel *GameOverLbl;//��Ϸ����
    QPushButton *PauseBtn;//��ͣ��ť
    QPushButton *ContinueBtn;//������ť
    QPushButton *QuitBtn;//�˳���ť
    QPushButton *YesBtn;
    QTimer *time;
    QTimer *time1;//�����ӵ����ٶ�
    QTimer *time2;//�ӵ��ƶ����ٶ�
    QTimer *time3;//�����л�С���е��ٶ�
    QTimer *time4;//advance
    QTimer *time5;//321
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path path;
    MyWidget *parent;
    QGraphicsScene *pScene;//����
    My_item_plane *item_plane;//ͼԪ
    QList<My_item_bullet *> my_bullte;//�ӵ�����
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
