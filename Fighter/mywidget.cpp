#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    mainsound=new QSound("img/image/media/menubg.wav",this);
    mainsound->setLoops(-1);
}

//ÊúÇÐ
void MyWidget::SetButtonStyleV(QPushButton *button, QString imgsrc, int CutSec)
{
    //=========================QssÇÐ¸îÍ¼Æ¬
    int img_w=QPixmap(imgsrc).width();
    int img_h=QPixmap(imgsrc).height();
    int PicWidth = img_w/CutSec;
    button->setFixedSize(PicWidth,img_h);
    button->setStyleSheet(QString("QPushButton{border-width: 41px; border-image: url(%1)  0 0 0 %2 repeat  repeat;border-width: 0px; border-radius: 0px;}")
      .append("QPushButton::hover,{border-image: url(%1) 0 0 0 %3  repeat  repeat;}")
      .append("QPushButton::pressed{border-image: url(%1) 0  0 0 %2 repeat  repeat;}")
      .append("QPushButton::checked{border-image: url(%1) 0  0 0 %2 repeat  repeat;}")
      .append("QPushButton::disabled{border-image: url(%1) 0  0 0 %2 repeat  repeat;}")
      .arg(imgsrc).arg(0).arg(PicWidth*1).arg(PicWidth*2).arg(PicWidth*3));
}

//ºáÇÐ
void MyWidget::SetButtonStyleH(QPushButton *button, QString imgsrc, int CutSec)
{
    //=========================QssÇÐ¸îÍ¼Æ¬
    int img_w=QPixmap(imgsrc).width();
    int img_h=QPixmap(imgsrc).height();
    int PicHeight = img_h/CutSec;
    button->setFixedSize(img_w,PicHeight);
    button->setStyleSheet(QString("QPushButton{border-width: 41px; border-image: url(%1)  %2 0 0 0  repeat  repeat;border-width: 0px; border-radius: 0px;}")
      .append("QPushButton::hover{border-image: url(%1) %3 0 0 0   repeat  repeat;}")
      .append("QPushButton::pressed{border-image: url(%1) %2 0  0 0  repeat  repeat;}")
      .append("QPushButton::checked{border-image: url(%1) %2 0  0 0  repeat  repeat;}")
      .append("QPushButton::disabled{border-image: url(%1) %2 0  0 0  repeat  repeat;}")
                          .arg(imgsrc).arg(0).arg(PicHeight*1).arg(PicHeight*2).arg(PicHeight*3));
}
