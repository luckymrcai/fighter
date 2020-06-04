#ifndef WIDGET_REGIST_H
#define WIDGET_REGIST_H


#include "mywidget.h"

class Widget_Regist : public MyWidget
{
    Q_OBJECT
public:
    explicit Widget_Regist(MyWidget *parent = 0);
    QLabel *RegistLbl;
    QPushButton *RegistBtn;
    QPushButton *ReturnBtn;
    QLineEdit *NameEdt;
    QLineEdit *PwdEdt;
    QLineEdit *PwdSecondEdt;
    QLineEdit *ResultEdt;//�ܱ���
    QComboBox *QuestionBox;//�ܱ�����������

signals:

public slots:
    void RegistBtnClick();
    void ReturnBtnClick();
    void NameEdtFocus();
};

#endif // REGIST_H
