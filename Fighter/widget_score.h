#ifndef WIDGET_SCORE_H
#define WIDGET_SCORE_H

#include "mywidget.h"
class Widget_Score :public MyWidget
{
    Q_OBJECT
public:
    Widget_Score(MyWidget *parent = 0);
    MyWidget *parent;
    QLabel *BoxLbl;
    QPushButton *YesBtn;//“Ù¿÷
public slots:
    void YesBtnClick();

};

#endif // WIDGET_SCORE_H
