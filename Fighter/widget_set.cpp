#include "widget_set.h"

Widget_Set::Widget_Set(MyWidget *parent)
    :MyWidget(parent)
{
    this->parent=parent;
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/mainpage/mainpage-bg.jpg").scaled(this->size())));
    this->setPalette(palette);

    //设置标题：欢迎来到银河世界
    QLabel *GifLbl=new QLabel(this);
    QMovie *movie=new QMovie("img/image/mainpage/333.gif");
    GifLbl->move(5,20);
    GifLbl->setMovie(movie);
    movie->start();

    //框
    BoxLbl=new QLabel(this);
    BoxLbl->setPixmap(QPixmap("img/image/set/box.png"));
    BoxLbl->setScaledContents(true);
    BoxLbl->setGeometry(20,70,600,850);

    //背景1
    Back1Lbl=new QLabel(this);
    Back1Lbl->setPixmap(QPixmap("img/image/set/back1.png"));
    Back1Lbl->move(0,this->height()-Back1Lbl->pixmap()->height());

    //背景2
    Back2Lbl=new QLabel(this);
    Back2Lbl->setPixmap(QPixmap("img/image/set/back2.png"));
    Back2Lbl->move(0,this->height()-Back2Lbl->pixmap()->height());

    //背景3
    Back3Lbl=new QLabel(this);
    Back3Lbl->setPixmap(QPixmap("img/image/set/back2.png"));
    Back3Lbl->move(this->width()-Back3Lbl->pixmap()->width(),this->height()-Back3Lbl->pixmap()->height());

    //背景_线条1
    QLabel *Line1Lbl=new QLabel(this);
    Line1Lbl->setPixmap(QPixmap("img/image/set/details-cutline.png"));
    Line1Lbl->setScaledContents(true);
    Line1Lbl->setGeometry(50,200,500,1);

    //背景_线条2
    QLabel *Line2Lbl=new QLabel(this);
    Line2Lbl->setPixmap(QPixmap("img/image/set/details-cutline.png"));
    Line2Lbl->setScaledContents(true);
    Line2Lbl->setGeometry(50,300,500,1);

    //背景_线条3
    QLabel *Line3Lbl=new QLabel(this);
    Line3Lbl->setPixmap(QPixmap("img/image/set/details-cutline.png"));
    Line3Lbl->setScaledContents(true);
    Line3Lbl->setGeometry(50,400,500,1);

    //背景_线条4
    QLabel *Line4Lbl=new QLabel(this);
    Line4Lbl->setPixmap(QPixmap("img/image/set/details-cutline.png"));
    Line4Lbl->setScaledContents(true);
    Line4Lbl->setGeometry(50,500,500,1);

    //背景_线条5
    QLabel *Line5Lbl=new QLabel(this);
    Line5Lbl->setPixmap(QPixmap("img/image/set/details-cutline.png"));
    Line5Lbl->setScaledContents(true);
    Line5Lbl->setGeometry(50,600,500,1);

    //背景_线条6
    QLabel *Line6Lbl=new QLabel(this);
    Line6Lbl->setPixmap(QPixmap("img/image/set/details-cutline.png"));
    Line6Lbl->setScaledContents(true);
    Line6Lbl->setGeometry(50,700,500,1);

    //文字：背景音乐
    QLabel *Word1Lbl=new QLabel("背景音乐",this);
    Word1Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word1Lbl->setGeometry(130,130,100,40);

    //文字：背景音效
    QLabel *Word2Lbl=new QLabel("背景音效",this);
    Word2Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word2Lbl->setGeometry(130,230,100,40);

    //文字：新手指引
    QLabel *Word3Lbl=new QLabel("新手指引",this);
    Word3Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word3Lbl->setGeometry(130,330,100,40);

    //文字：已登录
    QLabel *Word4Lbl=new QLabel("已登录",this);
    Word4Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word4Lbl->setGeometry(130,430,100,40);

    //文字：正在运行
    QLabel *Word5Lbl=new QLabel("正在运行",this);
    Word5Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word5Lbl->setGeometry(130,530,100,40);

    //文字：当前版本
    QLabel *Word6Lbl=new QLabel("当前版本",this);
    Word6Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word6Lbl->setGeometry(130,630,100,40);

    //文字：1.1
    QLabel *Word7Lbl=new QLabel("1.1",this);
    Word7Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word7Lbl->setGeometry(450,628,100,40);

    //文字：当前账号为至尊会员
    QLabel *Word8Lbl=new QLabel("当前账号为至尊会员",this);
    Word8Lbl->setStyleSheet("font-size: 25px;color:white;");
    Word8Lbl->setGeometry(130,730,500,40);

    //按钮：音乐
    MusicBtn=new QPushButton(this);
    MusicBtn->setStyleSheet("border-image:url(img/image/set/tick.png)");
    MusicBtn->setGeometry(430,120,70,70);
    MusicBtn->connect(MusicBtn,SIGNAL(clicked()),this,SLOT(MusicBtnClick()));

    //按钮：音效
    SoundEffectBtn=new QPushButton(this);
    if(CSingleton::SoundEffectFlag==false)
    {
        SoundEffectBtn->setStyleSheet("border-image:url(img/image/set/tick-bg.png)");
    }
    else
    {
        SoundEffectBtn->setStyleSheet("border-image:url(img/image/set/tick.png)");
    }
    SoundEffectBtn->setGeometry(430,220,70,70);
    SoundEffectBtn->connect(SoundEffectBtn,SIGNAL(clicked()),this,SLOT(SoundEffectBtnClick()));

    //按钮：新手指引
    GuideBtn=new QPushButton(this);
    CSingleton *UserImge=CSingleton::GetData("img/data.db");
    QSqlQuery query;
    query.exec("select *from tbl_score where user_name ='"+CSingleton::NowUserName+"' ");
    query.first();
//    qDebug()<<query.value(2).toString();
    if(query.value(0).toString()==NULL || query.value(2).toString()=="0")
    {
        GuideBtn->setStyleSheet("border-image:url(img/image/set/tick.png)");
//        qDebug()<<query.value(2).toString();
    }
    else
    {
        GuideBtn->setStyleSheet("border-image:url(img/image/set/tick-bg.png)");
    }
    GuideBtn->setGeometry(430,320,70,70);
    GuideBtn->connect(GuideBtn,SIGNAL(clicked()),this,SLOT(GuideBtnClick()));

    //按钮：注销
    LogoutBtn=new QPushButton(this);
    SetButtonStyleH(LogoutBtn,"img/image/set/b_logout.png",2);
    LogoutBtn->move(400,410);
    LogoutBtn->connect(LogoutBtn,SIGNAL(clicked()),this,SLOT(LogoutBtnClick()));

    //按钮：退出
    QuitBtn=new QPushButton(this);
    SetButtonStyleH(QuitBtn,"img/image/set/b_quit.png",2);
    QuitBtn->move(400,510);
    QuitBtn->connect(QuitBtn,SIGNAL(clicked()),this,SLOT(QuitBtnClick()));

    //按钮：帮助
    HelpBtn=new QPushButton(this);
    SetButtonStyleH(HelpBtn,"img/image/set/b_help1.png",2);
    HelpBtn->move(9,805);
    HelpBtn->connect(HelpBtn,SIGNAL(clicked()),this,SLOT(HelpBtnClick()));

    //按钮：返回
    ReturnBtn=new QPushButton(this);
    SetButtonStyleH(ReturnBtn,"img/image/set/b_return.png",2);
    ReturnBtn->move(519,810);
    ReturnBtn->connect(ReturnBtn,SIGNAL(clicked()),this,SLOT(ReturnBtnClick()));


    //帮助界面
    HelpLbl=new QLabel(this);
    HelpLbl->setPixmap(QPixmap("img/image/set/popup-bg1.png"));
    HelpLbl->setScaledContents(true);
    HelpLbl->setGeometry(20,180,600,700);
    HelpLbl->hide();
    HelpReturnBtn=new QPushButton(this);
    SetButtonStyleH(HelpReturnBtn,"img/image/set/b_return.png",2);
    HelpReturnBtn->move(500,770);
    HelpReturnBtn->connect(HelpReturnBtn,SIGNAL(clicked()),this,SLOT(HelpReturnBtnClick()));
    HelpReturnBtn->hide();

}

void Widget_Set::MusicBtnClick()
{
    static int flag=0;
    if(flag==0)
    {
        MusicBtn->setStyleSheet("border-image:url(img/image/set/tick-bg.png)");
        mainsound->stop();
        flag=1;
    }
    else
    {
        MusicBtn->setStyleSheet("border-image:url(img/image/set/tick.png)");
        mainsound->play();
        flag=0;
    }


}

void Widget_Set::SoundEffectBtnClick()
{
    if(CSingleton::SoundEffectFlag==false)
    {
        SoundEffectBtn->setStyleSheet("border-image:url(img/image/set/tick.png)");
        CSingleton::SoundEffectFlag=true;
    }
    else
    {
        SoundEffectBtn->setStyleSheet("border-image:url(img/image/set/tick-bg.png)");
        CSingleton::SoundEffectFlag=false;
    }
}

void Widget_Set::GuideBtnClick()
{
    CSingleton *UserImg=CSingleton::GetData("img/data.db");
    QSqlQuery query;
    query.exec("select *from tbl_score where user_name ='"+CSingleton::NowUserName+"' ");
    query.first();
    if(query.value(0).toString()==NULL || query.value(2).toString()=="0")
    {
        GuideBtn->setStyleSheet("border-image:url(img/image/set/tick-bg.png)");
        query.exec("update tbl_score set flag ='1' where user_name ='"+CSingleton::NowUserName+"'");
    }
    else
    {
        GuideBtn->setStyleSheet("border-image:url(img/image/set/tick.png)");
        query.exec("update tbl_score set flag ='0' where user_name ='"+CSingleton::NowUserName+"'");
    }
}

void Widget_Set::LogoutBtnClick()
{
    if(QMessageBox::Yes==QMessageBox::question(this, "注销",
                                   QString("是否注销游戏?"),
                                   QMessageBox::Yes | QMessageBox::No))
    {
        this->hide();
        this->parent->hide();
    }
}

void Widget_Set::QuitBtnClick()
{
    if(QMessageBox::Yes==QMessageBox::question(this, "退出",
                                   QString("是否退出游戏?"),
                                   QMessageBox::Yes | QMessageBox::No))
    {
        exit(0);
    }
}

void Widget_Set::HelpBtnClick()
{
    HelpLbl->show();
    HelpReturnBtn->show();
}

void Widget_Set::ReturnBtnClick()
{
    this->hide();
}

void Widget_Set::HelpReturnBtnClick()
{
    HelpLbl->hide();
    HelpReturnBtn->hide();
}


