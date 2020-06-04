#include "land.h"
#include <QDebug>
Land::Land(MyWidget *parent) :
    MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/login/cover.jpg").scaled(this->size())));
    this->setPalette(palette);

//    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏边框
//    this->setMouseTracking(true);//设置TRUE,让mousemoveevent生效。新版QT直接可以用

    //登录框
    LandLbl=new QLabel(this);
    LandLbl->setPixmap(QPixmap("img/image/login/login000.png"));
    LandLbl->setScaledContents(true);
    LandLbl->setGeometry(60,150,510,450);

    //登陆
    LandBtn=new QPushButton(this);
    SetButtonStyleH(LandBtn,"img/image/login/login004.png",2);
    LandBtn->connect(LandBtn,SIGNAL(clicked()),this,SLOT(LandBtnClick()));


    //返回
    ReturnBtn=new QPushButton(this);
    SetButtonStyleH(ReturnBtn,"img/image/login/login007.png",2);
    ReturnBtn->connect(ReturnBtn,SIGNAL(clicked()),this,SLOT(ReturnBtnClick()));

    //水平布局（登陆返回）
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(LandBtn);
    hboxlayout->addWidget(ReturnBtn);
    hboxlayout->setContentsMargins(0,600,0,0);

    //账号
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(240,350,280,50);
    NameEdt->setStyleSheet("background:transparent;border:0px");

    //密码
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(240,428,280,50);
    PwdEdt->setStyleSheet("background:transparent;border:0px");


}

void Land::LandBtnClick()
{

}

void Land::ReturnBtnClick()
{
    this->hide();
}


