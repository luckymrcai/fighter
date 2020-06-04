#include "widget_score.h"

Widget_Score::Widget_Score(MyWidget *parent)
    :MyWidget(parent)
{
    this->parent=parent;
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //ÉèÖÃ±³¾°
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/over/resultbg.jpg").scaled(this->size())));
    this->setPalette(palette);

    //¿ò
    BoxLbl=new QLabel(this);
    BoxLbl->setPixmap(QPixmap("img/image/over/result-endless-bg.png"));
    BoxLbl->setScaledContents(true);
    BoxLbl->setGeometry(0,0,BoxLbl->pixmap()->width(),BoxLbl->pixmap()->height());

    //°´Å¥£ºÈ·¶¨
    YesBtn=new QPushButton(this);
    SetButtonStyleH(YesBtn,"img/image/over/setup-savebutton.png",2);
    YesBtn->move(200,700);
    YesBtn->connect(YesBtn,SIGNAL(clicked()),this,SLOT(YesBtnClick()));

    //±³¾°ÒôÀÖ
    mainsound=new QSound("img/image/media/menubg.wav",this);
    mainsound->setLoops(-1);
    mainsound->play();

    //ÏÔÊ¾·ÖÊı
    QLabel *ScoreLbl=new QLabel(this);
    ScoreLbl->setGeometry(230,180,400,300);
    ScoreLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 80px;");
    ScoreLbl->setText(QString::number(CSingleton::NowUserScore));

}

void Widget_Score::YesBtnClick()
{
    //²¥·ÅÒôÀÖ
    mainsound=new QSound("img/image/media/menubg.wav",this);
    mainsound->setLoops(-1);
    mainsound->play();
    this->hide();
    delete this;
    this->parent->hide();
    delete this->parent;
}
