#ifndef WIDGET_MAIN_H
#define WIDGET_MAIN_H

#include "mywidget.h"
#include "widget_game.h"
#include "widget_set.h"
#include <QSound>
#include <QTextEdit>
class Widget_Main : public MyWidget
{
    Q_OBJECT
public:
    explicit Widget_Main(MyWidget *parent = 0);
    Widget_Game *GameWidget;
    Widget_Set *SetWidget;
    QLabel *MoreLbl;
    QTextEdit *RankEdt;
    QPushButton *ReturnBtn;
    QPushButton *LeftBtn;
    QPushButton *RightBtn;
    QString RankName[21];
    QString RankScore[21];
    void GetRank();

signals:

public slots:
    void EndlessModeBtnClick();
    void RushModeBtnClick();
    void WarehouseBtnClick();
    void PilotBtnClick();
    void InviteBtnClick();
    void SetBtnClick();
    void ReturnBtnClick();
    void LeftBtnClick();
    void RightBtnClick();
private:


};

#endif // MENU_H
