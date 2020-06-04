#ifndef WIDGET_SET_H
#define WIDGET_SET_H

#include "mywidget.h"
#include <QMovie>
#include <QMessageBox>
class Widget_Set: public MyWidget
{
    Q_OBJECT
public:
    Widget_Set(MyWidget *parent = 0);
    QLabel *BoxLbl;
    QLabel *Back1Lbl;
    QLabel *Back2Lbl;
    QLabel *Back3Lbl;
    QLabel *HelpLbl;
    QPushButton *MusicBtn;//音乐
    QPushButton *SoundEffectBtn;//音效
    QPushButton *GuideBtn;//新手指引
    QPushButton *LogoutBtn;//注销
    QPushButton *QuitBtn;//退出
    QPushButton *HelpBtn;//帮助
    QPushButton *ReturnBtn;//返回
    QPushButton *HelpReturnBtn;//帮助里面的返回键
    MyWidget *parent;

    //帮助
//    QLabel *Box1Lbl;

public slots:
    void MusicBtnClick();
    void SoundEffectBtnClick();
    void GuideBtnClick();
    void LogoutBtnClick();
    void QuitBtnClick();
    void HelpBtnClick();
    void ReturnBtnClick();
    void HelpReturnBtnClick();

};

#endif // WIDGET_SET_H
