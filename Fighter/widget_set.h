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
    QPushButton *MusicBtn;//����
    QPushButton *SoundEffectBtn;//��Ч
    QPushButton *GuideBtn;//����ָ��
    QPushButton *LogoutBtn;//ע��
    QPushButton *QuitBtn;//�˳�
    QPushButton *HelpBtn;//����
    QPushButton *ReturnBtn;//����
    QPushButton *HelpReturnBtn;//��������ķ��ؼ�
    MyWidget *parent;

    //����
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
