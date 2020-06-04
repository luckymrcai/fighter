#include "widget_login.h"
#include <QDebug>
Widget_Login::Widget_Login(MyWidget *parent) :
    MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);//����ԭ����

    //����
    this->setWindowTitle("����ս��");

    //ͼ��
    this->setWindowIcon(QIcon("img/image/login/Icon.png"));
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
    LandLbl->setGeometry(60,200,510,450);

    //��ť���ο͵�½
    TouristBtn=new QPushButton(this);
    SetButtonStyleH(TouristBtn,"img/image/login/guests.png",2);
    TouristBtn->move(110,580);
    TouristBtn->connect(TouristBtn,SIGNAL(clicked()),this,SLOT(TouristBtnClick()));

    //��ť����������
    ForgetPwdBtn=new QPushButton(this);
    SetButtonStyleH(ForgetPwdBtn,"img/image/login/guests(3).png",2);
    ForgetPwdBtn->move(310,580);
    ForgetPwdBtn->connect(ForgetPwdBtn,SIGNAL(clicked()),this,SLOT(ForgetPwdBtnClick()));

    //��ť����½
    LandBtn=new QPushButton(this);
    SetButtonStyleH(LandBtn,"img/image/login/butLogin.png",2);
    LandBtn->connect(LandBtn,SIGNAL(clicked()),this,SLOT(LandBtnClick()));

    //��ť��ע��
    RegistBtn=new QPushButton(this);
    SetButtonStyleH(RegistBtn,"img/image/login/butRegiste.png",2);
    RegistBtn->connect(RegistBtn,SIGNAL(clicked()),this,SLOT(RegistBtnClick()));


    //��ť���˳�
    QuitBtn=new QPushButton(this);
    QuitBtn->move(570,0);
    SetButtonStyleH(QuitBtn,"img/image/login/butClose.png",2);
    QuitBtn->connect(QuitBtn,SIGNAL(clicked()),this,SLOT(QuitBtnClick()));

    //ˮƽ���֣���½ע��
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(LandBtn);
    hboxlayout->addWidget(RegistBtn);
    hboxlayout->setContentsMargins(0,600,0,0);

    //�༭�����˺�
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(240,400,280,50);
    NameEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    NameEdt->setPlaceholderText("�������û���");//�û����༭����ʾ��Ϣ
    NameEdt->setMaxLength(12);//�޶����볤��
    NameEdt->setFocus();

    //������������
    QRegExp regexp("[A-Za-z0-9]{1,12}");//ֻ����Ӣ�Ļ�������
//    NameEdt->setValidator(new QRegExpValidator(regexp,this));

    //�༭��������
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(240,478,280,50);
    PwdEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdEdt->setPlaceholderText("������6-8λ����");//�û����༭����ʾ��Ϣ
    PwdEdt->setMaxLength(8);//�޶����볤��
    PwdEdt->setEchoMode(QLineEdit::Password);//�����ʽ���ڵ���ʾ
    QRegExp regexppwd("[0-9]{1,8}");//�޶�����ֻ��������
    PwdEdt->setValidator(new QRegExpValidator(regexppwd,this));

    //��������
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
        QMessageBox::warning(this,"����","�˺Ż����벻��Ϊ�գ�",QMessageBox::Ok);
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
            QMessageBox::warning(this,"����","�˺Ż��������",QMessageBox::Ok);
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
    if(QMessageBox::Yes==QMessageBox::question(this,"����","�����Ҫ���ˣ�",QMessageBox::Yes|QMessageBox::No))
    {
        close();
    }

}
