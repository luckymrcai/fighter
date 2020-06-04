#include <QtGui/QApplication>
#include <QTextCodec>
#include "widget_login.h"
#include <QDesktopWidget>
#include "widget_game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //±àÂë
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    Widget_Login *w=new Widget_Login;

//    Widget_Game w;
    w->show();
    w->move ((QApplication::desktop()->width() - w->width())/2,(QApplication::desktop()->height() - w->height())/2-50);
    return a.exec();
}
