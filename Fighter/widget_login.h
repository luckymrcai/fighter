#ifndef WIDGET_LOGIN_H
#define WIDGET_LOGIN_H

#include "mywidget.h"
#include "widget_regist.h"
#include "widget_main.h"
#include "widget_password.h"
class Widget_Login : public MyWidget
{
    Q_OBJECT
public:
    explicit Widget_Login(MyWidget *parent = 0);
//    void mousePressEvent(QMouseEvent *);
//    void mouseMoveEvent(QMouseEvent *);

    QLabel *LandLbl;            //登陆框
    QLineEdit *NameEdt;         //编辑条：账号
    QLineEdit *PwdEdt;          //编辑条：密码
    QPushButton *TouristBtn;    //按钮：游客登陆
    QPushButton *ForgetPwdBtn;  //按钮：忘记密码
    QPushButton *LandBtn;       //按钮：登陆
    QPushButton *RegistBtn;     //按钮：注册
    QPushButton *QuitBtn;
    Widget_Regist *RegistWidget;        //界面：注册
    Widget_Main *MainWidget;            //界面：主界面
    Widget_Password *PasswordWidget;    //界面：找回密码

private:
    QPoint mousePos;

public slots:
    void TouristBtnClick();     //槽函数：游客登录
    void ForgetPwdBtnClick();   //槽函数：忘记密码
    void LandBtnClick();        //槽函数：登陆
    void RegistBtnClick();      //槽函数：注册
    void QuitBtnClick();

};

#endif // LOGIN_H
