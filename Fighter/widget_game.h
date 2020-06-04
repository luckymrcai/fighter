#ifndef WIDGET_GAME_H
#define WIDGET_GAME_H

#include "mywidget.h"
#include "gameview.h"

class Widget_Game : public MyWidget
{
    Q_OBJECT

public:
    Widget_Game(MyWidget *parent = 0);
    Gameview *GameView;
    MyWidget *parent;
};

#endif // WIDGET_H
