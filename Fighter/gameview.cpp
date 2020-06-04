#include "gameview.h"
#include <QDebug>
#include "csingleton.h"

Gameview::Gameview(MyWidget *parent):QGraphicsView(parent)
{
    this->parent=parent;
    this->setFixedSize(640,950);
    this->setStyleSheet("background:transparent;border:0px");
    this->setMouseTracking(true);//����TRUE,��mousemoveevent��Ч���°�QTֱ�ӿ�����
    this->setFocus();
    pScene=new QGraphicsScene();
    pScene->setSceneRect(0,0,640,950);//���� ����ͼ ���� ��Сһ��
    this->setScene(pScene);//��ͼ���ó���

    item_plane=new My_item_plane("img/image/myplane/i-p-06c.png",pScene);
    item_plane->setPos(this->width()/2-40,this->height()-82);
    item_plane->setFocus();

    key_left=false;
    key_right=false;
    key_up=false;
    key_down=false;
    FireFlag=false;
    FileFlagMouse=false;

    //�÷�
    CSingleton::NowUserScore=0;
    this->CountDownFlag=0;
    ScoreLbl=new QLabel(this);
    ScoreLbl->setText("�÷֣�0");
    ScoreLbl->setGeometry(0,0,400,40);
    ScoreLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 40px;");

    //Ѫ��
    BloodLbl=new QLabel(this);
    BloodLbl->setText("�ҷ�Ѫ��:5");
    BloodLbl->setGeometry(450,0,400,40);
    BloodLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 25px;");

    //�л�Ѫ��
    EnemyBloodLbl=new QLabel(this);
    EnemyBloodLbl->setText("�л�Ѫ����");
    EnemyBloodLbl->setGeometry(280,0,400,40);
    EnemyBloodLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 25px;");

    //����ָ��
    GuideLbl=new QLabel(this);
    GuideLbl->setGeometry(50,320,600,400);
    GuideLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 40px;");

    //��ǩ��READY
    CountDownLbl=new QLabel(this);
    CountDownLbl->setGeometry(150,300,363,81);

    //��ͣ��
    PauseLbl=new QLabel(this);
    PauseLbl->setPixmap(QPixmap("img/image/gameview/box.png"));
    PauseLbl->setScaledContents(true);
    PauseLbl->setGeometry(110,200,400,200);
    PauseLbl->hide();

    //��Ϸ����
    GameOverLbl=new QLabel(this);
    GameOverLbl->setGeometry(230,160,400,200);
    GameOverLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 40px;");
    GameOverLbl->setText("��Ϸ����");
    GameOverLbl->hide();

    //��ť����ͣ
    PauseBtn=new QPushButton(this);
    SetButtonStyleH(PauseBtn,"img/image/gameview/pausebtn.png",2);
    PauseBtn->move(580,0);
    PauseBtn->connect(PauseBtn,SIGNAL(clicked()),this,SLOT(PauseBtnClick()));

    //��ť������
    ContinueBtn=new QPushButton(this);
    SetButtonStyleH(ContinueBtn,"img/image/gameview/button-blue-s2.png",2);
    ContinueBtn->move(150,270);
    ContinueBtn->connect(ContinueBtn,SIGNAL(clicked()),this,SLOT(ContinueBtnClick()));
    ContinueBtn->hide();

    //��ť���˳�
    QuitBtn=new QPushButton(this);
    SetButtonStyleH(QuitBtn,"img/image/gameview/b_quit.png",2);
    QuitBtn->move(330,270);
    QuitBtn->connect(QuitBtn,SIGNAL(clicked()),this,SLOT(QuitBtnClick()));
    QuitBtn->hide();

    //��ť��ȷ��
    YesBtn=new QPushButton(this);
    SetButtonStyleH(YesBtn,"img/image/gameview/setup-savebutton.png",2);
    YesBtn->move(170,310);
    YesBtn->connect(YesBtn,SIGNAL(clicked()),this,SLOT(YesBtnClick()));
    YesBtn->hide();

    //��ʱ�����ҷ��ɻ��ƶ�
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(plane_move()));
    time->stop();

    //��ʱ��1���ҷ��ӵ�����
    time1=new QTimer(this);
    connect(time1,SIGNAL(timeout()),this,SLOT(bullet_produce()));
    time1->stop();

    //��ʱ��2���ҷ��ӵ��ƶ�
    time2=new QTimer(this);
    connect(time2,SIGNAL(timeout()),this,SLOT(bullet_move()));
    time2->stop();

    //��ʱ��3���з�С������
    time3=new QTimer(this);
    connect(time3,SIGNAL(timeout()),this,SLOT(enemy_fish_produce()));
    time3->stop();

    //��ʱ��4���з�boss����ը���з�С���ƶ�
    time4=new QTimer(this);
    connect(time4,SIGNAL(timeout()),pScene,SLOT(advance()));
    time4->stop();

    //����ʱ
    time5=new QTimer(this);
    connect(time5,SIGNAL(timeout()),this,SLOT(count_down()));
    time5->start(1000);

    //��Ч
    mediaObject=new Phonon::MediaObject(this);
    mediaObject->setCurrentSource(Phonon::MediaSource("img/image/media/blast0.wav"));
    audioOutput=new Phonon::AudioOutput(Phonon::MusicCategory,this);
    path=Phonon::createPath(mediaObject,audioOutput);


}
//����ʱ
void Gameview::count_down()
{
    static int count=0;
    if(count==0)
    {
        qDebug()<<CSingleton::NowUserName;
        CSingleton *UserImg=CSingleton::GetData("img/data.db");
        QSqlQuery query;
        query.exec("select *from tbl_score where user_name ='"+CSingleton::NowUserName+"' ");
        query.first();
        QString UserFlag=query.value(2).toString();
        qDebug()<<"UserFlag:"<<UserFlag;
        if(query.value(0).toString()==NULL || UserFlag=="0")
        {
            qDebug()<<"�в���ָ��";
            GuideLbl->setText("����ָ��\n�ƶ�ս������ �� �� �� �����\n    ���䣺�ո�������\n     ESC����ͣ");
            if(query.value(2).toString()=="0")
            {
                query.exec("update tbl_score set flag ='1' where user_name ='"+CSingleton::NowUserName+"'");
                query.first();
            }
        }
        else
        {
            qDebug()<<"888";
        }
        count++;
    }
    else if(count==1)
    {
        mediaObject->setCurrentSource(Phonon::MediaSource("img/image/media/readygo.wav"));
        mediaObject->play();
        CountDownLbl->setStyleSheet("background-image:url(img/image/gameview/Ready_Txt_READY.png)");
        count++;
    }
    else if(count==2)
    {
        CountDownLbl->setStyleSheet("background-image:url(img/image/gameview/Ready_Txt_Go_1.png)");
        CountDownLbl->setGeometry(170,290,303,123);
        count++;
    }
    else if(count==3)
    {
        this->CountDownFlag=1;
        GuideLbl->hide();
        CountDownLbl->hide();
        time->start(10);
        time1->start(100);
        time2->start(10);
        time3->start(1000);
        time4->start(10);
        time5->stop();
        count=0;
    }
}

//���̰�ѹ�¼�
void Gameview::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())//��һ�ΰ��� false
    {
        switch(event->key())
        {
        case Qt::Key_Left:
        {
            key_left=true;
        }
        break;
        case Qt::Key_Right:
        {
            key_right=true;
        }
        break;
        case Qt::Key_Up:
        {
            key_up=true;
        }
        break;
        case Qt::Key_Down:
        {
            key_down=true;
        }
        break;
        case Qt::Key_Escape:
        {
            qDebug()<<"ESC";
        }
        break;
        case Qt::Key_Space:
        {
            FireFlag=true;
        }
        break;
        }
    }
}

//�����ͷ��¼�
void Gameview::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())//��һ�ΰ��� fause
    {
        switch(event->key())
        {
        case Qt::Key_Left:
        {
            key_left=false;
        }
        break;
        case Qt::Key_Right:
        {
            key_right=false;
        }
        break;
        case Qt::Key_Up:
        {
            key_up=false;
        }
        break;
        case Qt::Key_Down:
        {
            key_down=false;
        }
        break;
        case Qt::Key_Space:
        {
            FireFlag=false;
        }
        break;

        }
    }
}

//����ƶ��¼�
void Gameview::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        QPoint p;
        p=event->pos();
        if(p.x()>=(item_plane->x()-100) && p.x()<=(item_plane->x()+item_plane->pixmap.width()+100)&&
           p.y()>=(item_plane->y()-100) && p.y()<=(item_plane->y()+item_plane->pixmap.height()+100))
        {
            //����if�����˷ɻ������꣬�÷ɻ�������ʾ�ڶ����У�������ֻ��ʾһ��
            if(p.x()<item_plane->pixmap.width()/2)
                p.setX(item_plane->pixmap.width()/2);
            if(p.x()>this->width()-item_plane->pixmap.width()/2)
                p.setX(this->width()-item_plane->pixmap.width()/2);
            if(p.y()<item_plane->pixmap.height()/2)
                p.setY(item_plane->pixmap.height()/2);
            if(p.y()>this->height()-item_plane->pixmap.height()/2)
                p.setY(this->height()-item_plane->pixmap.height()/2);
            item_plane->setPos(p.x()-item_plane->pixmap.width()/2,p.y()-item_plane->pixmap.height()/2);
        }
    }
}

//��갴ѹ�¼�
void Gameview::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        QPoint p;
        p=event->pos();
        if(p.x()>=(item_plane->x()-100) && p.x()<=(item_plane->x()+item_plane->pixmap.width()+100) &&
           p.y()>=(item_plane->y()-100) && p.y()<=(item_plane->y()+item_plane->pixmap.height()+100))
        {
           FileFlagMouse=true;

        }
    }
}

//����ͷ��¼�
void Gameview::mouseReleaseEvent(QMouseEvent *event)
{
    FileFlagMouse=false;
}

//�ҷ��ɻ��ƶ�
void Gameview::plane_move()
{
    if(key_left==true)
    {
        if(item_plane->pos().x()>0)
        {
            item_plane->moveBy(-10,0);
        }
    }
    if(key_right==true)
    {
        if(item_plane->pos().x()<this->width()-82)
        {
            item_plane->moveBy(10,0);
        }
    }
    if(key_up==true)
    {
        if(item_plane->pos().y()>0)
        {
            item_plane->moveBy(0,-20);
        }
    }
    if(key_down==true)
    {
        if(item_plane->pos().y()<this->height()-82)
        {
            item_plane->moveBy(0,20);
        }
    }
}

//�ҷ��ӵ�����
void Gameview::bullet_produce()
{
//    if(FireFlag==true)
//    {
        my_bullte.append(new My_item_bullet("img/image/bullet/zidan.png",this->pScene));
        my_bullte.back()->setPos(item_plane->x(),item_plane->y()-100);
//    }
}

//�ҷ��ӵ��ƶ����ҷ��ɻ���ײ�¼����ҷ��ӵ���ײ�¼���
void Gameview::bullet_move()
{
    int BulletFlag=0;//�ӵ���ʧ��־λ
    static int mortality=0;//������С����Ŀ
    //�ҷ��ɻ������ײ
    if(item_plane->collidingItems().count()>0)
    {
        QList<QGraphicsItem *>list_enemy=item_plane->collidingItems();
        QList<QGraphicsItem *>::Iterator itp;
        Enemy_Fish *enemy;
        for(itp=list_enemy.begin();itp!=list_enemy.end();itp++)
        {
            enemy=(Enemy_Fish *)(*itp);
            if(enemy->m_type==ENEMY_BULLET)
            {
                if(item_plane->x()+41>enemy->x()+5 && item_plane->x()+41<enemy->x()+enemy->pixmap.width()-5&&
                   item_plane->y()+41>enemy->y()+5 && item_plane->y()+41<enemy->y()+enemy->pixmap.height()-5)
                {
                    //��ը
                    Enemy_Blast *item_blast=new Enemy_Blast("img/image/gameview/boom01.png",pScene);
                    item_blast->setPos(item_plane->x(),item_plane->y());
                    enemy->hide();
                    delete enemy;//�л��ӵ���ʧ
                    item_plane->Blood--;//�ҷ��ɻ�Ѫ��
                    char MyBlood[100];
                    sprintf(MyBlood,"�ҷ�Ѫ��:%d",item_plane->Blood);
                    BloodLbl->setText(MyBlood);
                }
            }
            else if(enemy->m_type==ENEMY_FISH || enemy->m_type==ENEMY_BOSS)
            {
                //��ը
                Enemy_Blast *item_blast=new Enemy_Blast("img/image/gameview/boom01.png",pScene);
                item_blast->setPos(item_plane->x(),item_plane->y());
                item_plane->Blood=0;
                char MyBlood[100];
                sprintf(MyBlood,"�ҷ�Ѫ��:%d",item_plane->Blood);
                BloodLbl->setText(MyBlood);
            }
            //�ض�ʱ��������ʾ
            if(item_plane->Blood==0)
            {
                Enemy_Blast *item_blast=new Enemy_Blast("img/image/gameview/boom01.png",pScene);
                item_blast->setPos(item_plane->x(),item_plane->y());
                time->stop();
                time1->stop();
                time2->stop();
                time3->stop();
                time4->stop();
                mortality=0;
                SaveScore();
                item_plane->hide();
                PauseLbl->show();
                YesBtn->show();
                GameOverLbl->show();
            }
        }
    }
    //�ӵ��ƶ��ͼ����ײ
    for(int i=0;i<my_bullte.size();i++)
    {
        my_bullte[i]->moveBy(0,-40);
        if(my_bullte[i]->y()<-500)
        {
            my_bullte[i]->hide();
            delete my_bullte.at(i);
            my_bullte.removeAt(i);
        }
        if(my_bullte[i]->collidingItems().count()>0)
        {
            QList<QGraphicsItem *>list=my_bullte[i]->collidingItems();
            QList<QGraphicsItem *>::Iterator it;
            Enemy_Fish *enemy;
            for(it=list.begin();it!=list.end();it++)
            {
                enemy=(Enemy_Fish *)(*it);
                if(enemy->m_type==ENEMY_FISH ||enemy->m_type==ENEMY_BOSS)
                {
                    CSingleton::NowUserScore+=enemy->Score;//�����Ӽ�
                    ShowScore();//��ʾ����
                    enemy->Blood-=my_bullte[i]->strength;//���ٵл�Ѫ��
                    char E_Score[100];
                    sprintf(E_Score,"�л�Ѫ��:%d",enemy->Blood);
                    EnemyBloodLbl->setText(E_Score);
                    if(enemy->Blood<=0)
                    {
                        if(enemy->m_type==ENEMY_BOSS)
                        {
                            time3->start(9000/mortality);
                        }
                        if(CSingleton::SoundEffectFlag==true)
                        {
                            //��Ч
                            mediaObject->setCurrentSource(Phonon::MediaSource("img/image/media/blast0.wav"));
                            mediaObject->play();
                        }
                        //��ը
                        Enemy_Blast *item_blast=new Enemy_Blast("img/image/gameview/boom01.png",pScene);
                        item_blast->setPos(enemy->x(),enemy->y());
                        //�л���ʧ
                        enemy->hide();
                        delete enemy;
                        //�����Ӽ�*10
                        CSingleton::NowUserScore+=(enemy->Score*10);
                        ShowScore();
                        mortality++;
//                        my_bullte[i]->hide();
                    }
                    BulletFlag=1;
                }
                else
                {
                    BulletFlag=0;
                }
            }
            if(BulletFlag==1)
            {
                my_bullte[i]->hide();
                delete my_bullte.at(i);
                my_bullte.removeAt(i);
            }
        }
    }
    //����BOSS
    if(mortality>10 && mortality%10==1)
    {
        Enemy_Boss *enemy_boss=new Enemy_Boss("img/image/enemy/mini-boss00-1.png",this->pScene);
        mortality++;
        time3->stop();
    }
}

//�з��ɻ�����
void Gameview::enemy_fish_produce()
{
    Enemy_Fish *enemy_fish=new Enemy_Fish("img/image/enemy/i-p-04a.png",this->pScene);
    enemy_fish->setPos(qrand()%600,0);
}

//�÷���ʾ
void Gameview::ShowScore()
{
    char T_Score[100];
    sprintf(T_Score,"�÷�:%d",CSingleton::NowUserScore);
    ScoreLbl->setText(T_Score);
}

//�ۺ�������ͣ
void Gameview::PauseBtnClick()
{
    if(this->CountDownFlag==0)
    {
        time5->stop();
    }
    else
    {
        time->stop();
        time1->stop();
        time2->stop();
        time3->stop();
        time4->stop();
    }
    time->stop();
    time1->stop();
    time2->stop();
    time3->stop();
    time4->stop();
    time5->stop();
    PauseLbl->show();
    ContinueBtn->show();
    QuitBtn->show();
}

//�ۺ���������
void Gameview::ContinueBtnClick()
{
    if(this->CountDownFlag==0)
    {
        time5->start(1000);
    }
    else
    {
        time->start(10);
        time1->start(100);
        time2->start(5);
        time3->start(700);
        time4->start(10);
    }
    PauseLbl->hide();
    ContinueBtn->hide();
    QuitBtn->hide();
}

//�ۺ������˳�
void Gameview::QuitBtnClick()
{
    this->hide();
    this->parent->hide();
    delete this;
    delete this->parent;

}
void Gameview::SetButtonStyleH(QPushButton *button, QString imgsrc, int CutSec)
{
    //=========================Qss�и�ͼƬ
    int img_w=QPixmap(imgsrc).width();
    int img_h=QPixmap(imgsrc).height();
    int PicHeight = img_h/CutSec;
    button->setFixedSize(img_w,PicHeight);
    button->setStyleSheet(QString("QPushButton{border-width: 41px; border-image: url(%1)  %2 0 0 0  repeat  repeat;border-width: 0px; border-radius: 0px;}")
      .append("QPushButton::hover{border-image: url(%1) %3 0 0 0   repeat  repeat;}")
      .append("QPushButton::pressed{border-image: url(%1) %2 0  0 0  repeat  repeat;}")
      .append("QPushButton::checked{border-image: url(%1) %2 0  0 0  repeat  repeat;}")
      .append("QPushButton::disabled{border-image: url(%1) %2 0  0 0  repeat  repeat;}")
                          .arg(imgsrc).arg(0).arg(PicHeight*1).arg(PicHeight*2).arg(PicHeight*3));
}

void Gameview::YesBtnClick()
{
    Widget_Score *scorewidget=new Widget_Score(this->parent);
    scorewidget->show();
    this->hide();
    delete this;
}

void Gameview::SaveScore()
{
    CSingleton *UserImg=CSingleton::GetData("img/data.db");
    QSqlQuery query;
    query.exec("select *from tbl_score where user_name ='"+CSingleton::NowUserName+"' ");
    query.first();
    if(query.value(0).toString()!=NULL)
    {
        if(CSingleton::NowUserScore>query.value(1).toInt())
        {
            qDebug()<<"�������";
            qDebug()<<CSingleton::NowUserScore;
            QString update_sql="update tbl_score set max_score=? where user_name ='"+CSingleton::NowUserName+"'";
            query.prepare(update_sql);
            query.addBindValue(CSingleton::NowUserScore);
            query.exec();
        }
    }
}





