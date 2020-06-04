#include "widget_password.h"

Widget_Password::Widget_Password(MyWidget *parent)
    :MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/login/cover.jpg").scaled(this->size())));
    this->setPalette(palette);

//    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏边框

    //找回密码框
    PasswordLbl=new QLabel(this);
    PasswordLbl->setPixmap(QPixmap("img/image/login/login0002.png"));
    PasswordLbl->setScaledContents(true);
    PasswordLbl->setGeometry(42,210,PasswordLbl->pixmap()->width(),PasswordLbl->pixmap()->height());

    //按钮：确定
    YesBtn=new QPushButton(this);
    SetButtonStyleH(YesBtn,"img/image/login/uit0010 -1.png",2);
    YesBtn->connect(YesBtn,SIGNAL(clicked()),this,SLOT(YesBtnClick()));

    //按钮：取消
    NoBtn=new QPushButton(this);
    SetButtonStyleH(NoBtn,"img/image/login/uit0009 - 1.png",2);
    NoBtn->connect(NoBtn,SIGNAL(clicked()),this,SLOT(NoBtnClick()));

    //水平布局（确定取消）
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(YesBtn);
    hboxlayout->addWidget(NoBtn);
    hboxlayout->setContentsMargins(160,270,160,0);

    //编辑条：账号
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(250,285,260,45);
    NameEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    NameEdt->setPlaceholderText("请输入用户名");//用户名编辑框提示信息
    NameEdt->setMaxLength(12);//限定输入长度
    QRegExp regexp("[A-Za-z0-9]{1,12}");//输入类型限制//只能是英文或者数字
//    NameEdt->setValidator(new QRegExpValidator(regexp,this));

    //密保问题
    QuestionLbl=new QLabel(this);
    QuestionLbl->setGeometry(250,360,260,45);
    QuestionLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 25px;");


    //编辑条：答案
    ResultEdt=new QLineEdit(this);
    ResultEdt->setGeometry(250,428,260,45);
    ResultEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    ResultEdt->setPlaceholderText("请输入密保答案");//密保答案提示信息
    ResultEdt->setMaxLength(12);//限定输入长度


    //编辑条：密码
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(250,500,260,45);
    PwdEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdEdt->setPlaceholderText("请输入6-8位数字");//密码编辑框提示信息
    PwdEdt->setMaxLength(8);//限定输入长度
    PwdEdt->setEchoMode(QLineEdit::Password);//密码格式，黑点显示
    QRegExp regexppwd("[0-9]{1,8}");//限定密码只能是数字
    PwdEdt->setValidator(new QRegExpValidator(regexppwd,this));


    connect(NameEdt,SIGNAL(editingFinished()),this,SLOT(NameEdtFocus()));

}

void Widget_Password::YesBtnClick()
{

    QString Name=NameEdt->text();
    QString Answer=ResultEdt->text();
    QString Pwd=PwdEdt->text();
    if(NameEdt->text()==NULL)//用户名不为空判断
    {
        QMessageBox::warning(this,"提示","请输入用户名",QMessageBox::Ok);
    }
    else
    {


        if(PwdEdt->text().count()<6)//密码位数判断
        {
            QMessageBox::warning(this,"提示","密码需6位数及以上",QMessageBox::Ok);
        }
        else
        {
            if(Answer==UserAnswer)
            {
                qDebug()<<"666";
                CSingleton *UserImg=CSingleton::GetData("img/data.db");
                QSqlQuery query;
                query.exec("update tbl_user set password='"+Pwd+"' where user_name ='"+Name+"'");
                QMessageBox::information(this,"信息","修改成功",QMessageBox::Ok);

            }
            else
            {
                QMessageBox::warning(this,"提示","密保答案错误",QMessageBox::Ok);
            }
        }

    }

}

void Widget_Password::NoBtnClick()
{
    this->hide();
}

void Widget_Password::NameEdtFocus()
{
    QString Name=NameEdt->text();
    if(NameEdt->text()==NULL)//用户名不为空判断
    {
        QMessageBox::warning(this,"提示","请输入用户名",QMessageBox::Ok);
    }
    else
    {
        CSingleton *UserImg=CSingleton::GetData("img/data.db");
        QSqlQuery query;
        query.exec("select *from tbl_user where user_name ='"+Name+"' ");
        query.first();
        if(query.value(0).toString()==NULL)
        {
            qDebug()<<"不存在"<<endl;
            QMessageBox::warning(this,"提示","该用户名不存在",QMessageBox::Ok);
        }
        else
        {
    //        query.exec("insert into tbl_user values('"+name+"','"+pwd+"','"+question+"','"+anwser+"')");
            qDebug()<<query.value(2);
            QString Question=query.value(2).toString();
            QuestionLbl->setText(Question);
            UserAnswer=query.value(3).toString();
        }
    }
}

