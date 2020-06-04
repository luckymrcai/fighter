#ifndef WIDGET_PASSWORD_H
#define WIDGET_PASSWORD_H

#include "mywidget.h"
class Widget_Password : public MyWidget
{
    Q_OBJECT
public:
    Widget_Password(MyWidget *parent = 0);
    QLabel *PasswordLbl;
    QLabel *QuestionLbl;
    QPushButton *YesBtn;
    QPushButton *NoBtn;
    QLineEdit *NameEdt;
    QLineEdit *ResultEdt;
    QLineEdit *PwdEdt;
    QString UserAnswer;


signals:

public slots:
    void YesBtnClick();
    void NoBtnClick();
    void NameEdtFocus();
};

#endif // WIDGET_FORGETPWD_H
