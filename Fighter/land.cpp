#include "land.h"
#include <QDebug>
Land::Land(MyWidget *parent) :
    MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //���ñ���
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/login/cover.jpg").scaled(this->size())));
    this->setPalette(palette);

//    this->setWindowFlags(Qt::FramelessWindowHint);//���ر߿�
//    this->setMouseTracking(true);//����TRUE,��mousemoveevent��Ч���°�QTֱ�ӿ�����

    //��¼��
    LandLbl=new QLabel(this);
    LandLbl->setPixmap(QPixmap("img/image/login/login000.png"));
    LandLbl->setScaledContents(true);
    LandLbl->setGeometry(60,150,510,450);

    //��½
    LandBtn=new QPushButton(this);
    SetButtonStyleH(LandBtn,"img/image/login/login004.png",2);
    LandBtn->connect(LandBtn,SIGNAL(clicked()),this,SLOT(LandBtnClick()));


    //����
    ReturnBtn=new QPushButton(this);
    SetButtonStyleH(ReturnBtn,"img/image/login/login007.png",2);
    ReturnBtn->connect(ReturnBtn,SIGNAL(clicked()),this,SLOT(ReturnBtnClick()));

    //ˮƽ���֣���½���أ�
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(LandBtn);
    hboxlayout->addWidget(ReturnBtn);
    hboxlayout->setContentsMargins(0,600,0,0);

    //�˺�
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(240,350,280,50);
    NameEdt->setStyleSheet("background:transparent;border:0px");

    //����
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


