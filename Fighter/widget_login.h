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

    QLabel *LandLbl;            //��½��
    QLineEdit *NameEdt;         //�༭�����˺�
    QLineEdit *PwdEdt;          //�༭��������
    QPushButton *TouristBtn;    //��ť���ο͵�½
    QPushButton *ForgetPwdBtn;  //��ť����������
    QPushButton *LandBtn;       //��ť����½
    QPushButton *RegistBtn;     //��ť��ע��
    QPushButton *QuitBtn;
    Widget_Regist *RegistWidget;        //���棺ע��
    Widget_Main *MainWidget;            //���棺������
    Widget_Password *PasswordWidget;    //���棺�һ�����

private:
    QPoint mousePos;

public slots:
    void TouristBtnClick();     //�ۺ������ο͵�¼
    void ForgetPwdBtnClick();   //�ۺ�������������
    void LandBtnClick();        //�ۺ�������½
    void RegistBtnClick();      //�ۺ�����ע��
    void QuitBtnClick();

};

#endif // LOGIN_H
