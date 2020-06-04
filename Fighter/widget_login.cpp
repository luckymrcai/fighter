#include "widget_login.h"
#include <QDebug>
Widget_Login::Widget_Login(MyWidget *parent) :
    MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);//覆盖原窗口

    //标题
    this->setWindowTitle("雷霆战机");

    //图标
    this->setWindowIcon(QIcon("img/image/login/Icon.png"));
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
    LandLbl->setGeometry(60,200,510,450);

    //按钮：游客登陆
    TouristBtn=new QPushButton(this);
    SetButtonStyleH(TouristBtn,"img/image/login/guests.png",2);
    TouristBtn->move(110,580);
    TouristBtn->connect(TouristBtn,SIGNAL(clicked()),this,SLOT(TouristBtnClick()));

    //按钮：忘记密码
    ForgetPwdBtn=new QPushButton(this);
    SetButtonStyleH(ForgetPwdBtn,"img/image/login/guests(3).png",2);
    ForgetPwdBtn->move(310,580);
    ForgetPwdBtn->connect(ForgetPwdBtn,SIGNAL(clicked()),this,SLOT(ForgetPwdBtnClick()));

    //按钮：登陆
    LandBtn=new QPushButton(this);
    SetButtonStyleH(LandBtn,"img/image/login/butLogin.png",2);
    LandBtn->connect(LandBtn,SIGNAL(clicked()),this,SLOT(LandBtnClick()));

    //按钮：注册
    RegistBtn=new QPushButton(this);
    SetButtonStyleH(RegistBtn,"img/image/login/butRegiste.png",2);
    RegistBtn->connect(RegistBtn,SIGNAL(clicked()),this,SLOT(RegistBtnClick()));


    //按钮：退出
    QuitBtn=new QPushButton(this);
    QuitBtn->move(570,0);
    SetButtonStyleH(QuitBtn,"img/image/login/butClose.png",2);
    QuitBtn->connect(QuitBtn,SIGNAL(clicked()),this,SLOT(QuitBtnClick()));

    //水平布局：登陆注册
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(LandBtn);
    hboxlayout->addWidget(RegistBtn);
    hboxlayout->setContentsMargins(0,600,0,0);

    //编辑条：账号
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(240,400,280,50);
    NameEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    NameEdt->setPlaceholderText("请输入用户名");//用户名编辑框提示信息
    NameEdt->setMaxLength(12);//限定输入长度
    NameEdt->setFocus();

    //输入类型限制
    QRegExp regexp("[A-Za-z0-9]{1,12}");//只能是英文或者数字
//    NameEdt->setValidator(new QRegExpValidator(regexp,this));

    //编辑条：密码
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(240,478,280,50);
    PwdEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdEdt->setPlaceholderText("请输入6-8位数字");//用户名编辑框提示信息
    PwdEdt->setMaxLength(8);//限定输入长度
    PwdEdt->setEchoMode(QLineEdit::Password);//密码格式，黑点显示
    QRegExp regexppwd("[0-9]{1,8}");//限定密码只能是数字
    PwdEdt->setValidator(new QRegExpValidator(regexppwd,this));

    //播放音乐
    mainsound=new QSound("img/image/media/menubg.wav",this);
    mainsound->setLoops(-1);
    mainsound->play();


}

//void Widget_Widget_Widget_Login::mousePressEvent(QMouseEvent *event)
//{
//    mousePos=event->globalPos()-frameGeometry().topLeft();

//    event->accept();

//}

//void Widget_Widget_Widget_Login::mouseMoveEvent(QMouseEvent *event)
//{
//    if(event->buttons()==Qt::LeftButton)
//    {
//        move(event->globalPos()-mousePos);
//        event->accept();
////        qDebug("11");
//    }

//}



void Widget_Login::TouristBtnClick()
{
    MainWidget=new Widget_Main(this);
    MainWidget->show();
}
void Widget_Login::ForgetPwdBtnClick()
{
    PasswordWidget=new Widget_Password(this);
    PasswordWidget->show();
}

void Widget_Login::LandBtnClick()
{
    if(NameEdt->text()==NULL || PwdEdt->text()==NULL)
    {
        QMessageBox::warning(this,"警告","账号或密码不能为空！",QMessageBox::Ok);
    }
    else
    {
        QString Name=NameEdt->text();
        QString Pwd=PwdEdt->text();
        CSingleton *UserImg=CSingleton::GetData("img/data.db");
        if(UserImg->CheckUser(Name,Pwd))
        {

            MainWidget=new Widget_Main(this);
            MainWidget->show();
        }
        else
        {
            QMessageBox::warning(this,"警告","账号或密码错误！",QMessageBox::Ok);
        }


    }



}

void Widget_Login::RegistBtnClick()
{
    RegistWidget=new Widget_Regist(this);
    RegistWidget->show();
}



void Widget_Login::QuitBtnClick()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"问题","你这就要走了？",QMessageBox::Yes|QMessageBox::No))
    {
        close();
    }

}
