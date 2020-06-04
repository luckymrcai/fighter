#include "widget_main.h"
#include <QMovie>
Widget_Main::Widget_Main(MyWidget *parent) :
    MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //���ñ���
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/mainpage/mainpage-bg.jpg").scaled(this->size())));
    this->setPalette(palette);

    //���ñ��⣺��ӭ������������
    QLabel *GifLbl=new QLabel(this);
    QMovie *movie=new QMovie("img/image/mainpage/333.gif");
    GifLbl->move(5,20);
    GifLbl->setMovie(movie);
    movie->start();

    //UI_����
    QLabel *LineLbl=new QLabel(this);
    LineLbl->setPixmap(QPixmap("img/image/mainpage/mainpage-bg-line.png"));
    LineLbl->move(0,480);

    //UI_��_���а�
    QLabel *RankLbl=new QLabel(this);
    RankLbl->setPixmap(QPixmap("img/image/mainpage/popup-bg1.png"));
    RankLbl->setGeometry(0,70,640,600);

    //��ȡ���а���Ϣ
    RankEdt=new QTextEdit(this);
    RankEdt->setGeometry(20,100,620,600);
    RankEdt->setStyleSheet("background:transparent;border:0px;color:white;font-size: 40px;");
    RankEdt->setReadOnly(true);//ֻ��
    GetRank();

    //UI_����1
    QLabel *Bg001Lbl=new QLabel(this);
    Bg001Lbl->setPixmap(QPixmap("img/image/mainpage/mainpage-bg001.png"));
    Bg001Lbl->move((this->width()-Bg001Lbl->pixmap()->width())/2,725);

    //UI_����2
    QLabel *Bg002Lbl=new QLabel(this);
    Bg002Lbl->setPixmap(QPixmap("img/image/mainpage/mainpage-bg002.png"));
    Bg002Lbl->move(0,695);

    //UI_����3
    QLabel *Bg003Lbl=new QLabel(this);
    Bg003Lbl->setPixmap(QPixmap("img/image/mainpage/mainpage-bg003.png"));
    Bg003Lbl->move(this->width()-Bg003Lbl->pixmap()->width(),695);

    //UI_����4
    QLabel *Bg004Lbl=new QLabel(this);
    Bg004Lbl->setPixmap(QPixmap("img/image/mainpage/mainpage-bg004.png"));
    Bg004Lbl->move(0,this->height()-Bg004Lbl->pixmap()->height());

    //��ť���޾�ģʽ
    QPushButton *EndlessModeBtn=new QPushButton(this);
    SetButtonStyleH(EndlessModeBtn,"img/image/mainpage/mainpage-button-bg006.png",2);
    EndlessModeBtn->move(0,this->height()-EndlessModeBtn->height());
    EndlessModeBtn->connect(EndlessModeBtn,SIGNAL(clicked()),this,SLOT(EndlessModeBtnClick()));

    //��ť������ģʽ
    QPushButton *RushModeBtn=new QPushButton(this);
    SetButtonStyleH(RushModeBtn,"img/image/mainpage/mainpage-button-bg003.png",2);
    RushModeBtn->move(this->width()-RushModeBtn->width(),this->height()-EndlessModeBtn->height());
    RushModeBtn->connect(RushModeBtn,SIGNAL(clicked()),this,SLOT(RushModeBtnClick()));

    //��ť����ʻԱ
    QPushButton *PilotBtn=new QPushButton(this);
    SetButtonStyleH(PilotBtn,"img/image/mainpage/button-pilot.png",2);
    PilotBtn->move(152,722);
    PilotBtn->connect(PilotBtn,SIGNAL(clicked()),this,SLOT(PilotBtnClick()));

    //��ť���ֿ�
    QPushButton *WarehouseBtn=new QPushButton(this);
    SetButtonStyleH(WarehouseBtn,"img/image/mainpage/button-warehouse.png",2);
    WarehouseBtn->move(320,722);
    WarehouseBtn->connect(WarehouseBtn,SIGNAL(clicked()),this,SLOT(WarehouseBtnClick()));

    //��ť������
    QPushButton *InviteBtn=new QPushButton(this);
    SetButtonStyleH(InviteBtn,"img/image/mainpage/invite.png",2);
    InviteBtn->move(0,Bg002Lbl->y());
    InviteBtn->connect(InviteBtn,SIGNAL(clicked()),this,SLOT(InviteBtnClick()));

    //��ť������
    QPushButton *SetBtn=new QPushButton(this);
    SetButtonStyleH(SetBtn,"img/image/mainpage/set.png",2);
    SetBtn->move(this->width()-SetBtn->width()+10,Bg003Lbl->y());
    SetBtn->connect(SetBtn,SIGNAL(clicked()),this,SLOT(SetBtnClick()));

    //��ť����
    LeftBtn=new QPushButton(this);
    LeftBtn->setStyleSheet("border-image:url(img/image/mainpage/jiantou1.png)");
    LeftBtn->setGeometry(210,580,80,90);
    LeftBtn->connect(LeftBtn,SIGNAL(clicked()),this,SLOT(LeftBtnClick()));
    LeftBtn->hide();

    //��ť����
    RightBtn=new QPushButton(this);
    RightBtn->setStyleSheet("border-image:url(img/image/mainpage/jiantou.png)");
    RightBtn->setGeometry(380,580,80,90);
    RightBtn->connect(RightBtn,SIGNAL(clicked()),this,SLOT(RightBtnClick()));

    //�򣺸��๦�ܣ������ڴ�
    MoreLbl=new QLabel(this);
    MoreLbl->setPixmap(QPixmap("img/image/mainpage/more1.png"));
    MoreLbl->move(0,0);
    MoreLbl->hide();

    //��ť������
    ReturnBtn=new QPushButton(this);
    SetButtonStyleH(ReturnBtn,"img/image/mainpage/b_return.png",2);
    ReturnBtn->move(510,830);
    ReturnBtn->connect(ReturnBtn,SIGNAL(clicked()),this,SLOT(ReturnBtnClick()));
    ReturnBtn->hide();

    //���ý���
    SetWidget=new Widget_Set(this);
    SetWidget->show();
    SetWidget->hide();

    //��������
    mainsound=new QSound("img/image/media/menubg.wav",this);
    mainsound->setLoops(-1);
    mainsound->play();


}

void Widget_Main::EndlessModeBtnClick()
{
    GameWidget=new Widget_Game(this);
    GameWidget->show();
    gamesound=new QSound("img/image/media/gamebg0.wav",this);
    gamesound->setLoops(-1);
    gamesound->play();
}

void Widget_Main::RushModeBtnClick()
{
    MoreLbl->show();
    ReturnBtn->show();

}

void Widget_Main::WarehouseBtnClick()
{
    MoreLbl->show();
    ReturnBtn->show();
}

void Widget_Main::PilotBtnClick()
{
    MoreLbl->show();
    ReturnBtn->show();
}


void Widget_Main::InviteBtnClick()
{
    MoreLbl->show();
    ReturnBtn->show();
}

void Widget_Main::SetBtnClick()
{
    SetWidget->show();

}

void Widget_Main::ReturnBtnClick()
{
    MoreLbl->hide();
    ReturnBtn->hide();
}

void Widget_Main::GetRank()
{
    int i=1;
    CSingleton *UserImg=CSingleton::GetData("img/data.db");
    QSqlQuery query;
    query.exec("select *from tbl_score order by max_score desc limit 10");
    RankEdt->append("\t\t�� �� ��\t\t�� ��");
    while(query.next())
    {
        RankName[i]=query.value(0).toString();
        RankScore[i]=query.value(1).toString();
        char RankBuff[200];
        sprintf(RankBuff,"%2d%14s%13s",i,RankName[i].toStdString().c_str(),RankScore[i].toStdString().c_str());
        RankEdt->append(RankBuff);
        i++;
    }
}

void Widget_Main::LeftBtnClick()
{
    RankEdt->clear();
    int i=1;
    CSingleton *UserImg=CSingleton::GetData("img/data.db");
    QSqlQuery query;
    query.exec("select *from tbl_score order by max_score desc limit 10");
    RankEdt->append("\t\t�� �� ��\t\t�� ��");
    while(query.next())
    {
        RankName[i]=query.value(0).toString();
        RankScore[i]=query.value(1).toString();
        char RankBuff[200];
        sprintf(RankBuff,"%2d%14s%13s",i,RankName[i].toStdString().c_str(),RankScore[i].toStdString().c_str());
        RankEdt->append(RankBuff);
        i++;
    }
    LeftBtn->hide();
    RightBtn->show();
}

void Widget_Main::RightBtnClick()
{
    RankEdt->clear();
    int i=1;
    CSingleton *UserImg=CSingleton::GetData("img/data.db");
    QSqlQuery query;
    query.exec("select *from tbl_score order by max_score desc limit 10,10");
    RankEdt->append("\t\t�� �� ��\t\t�� ��");
    while(query.next())
    {
        RankName[i]=query.value(0).toString();
        RankScore[i]=query.value(1).toString();
        char RankBuff[200];
        sprintf(RankBuff,"%2d%14s%13s",i+10,RankName[i].toStdString().c_str(),RankScore[i].toStdString().c_str());
        RankEdt->append(RankBuff);
        i++;
    }
    LeftBtn->show();
    RightBtn->hide();
}

