#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QMouseEvent>
#include <QPalette>
#include <QPoint>
#include <QSound>
#include <QRegExp>
#include <QRegExpValidator>
#include <QComboBox>//ÏÂÀ­¿ò
#include <QDebug>
#include "csingleton.h"
#include <QMessageBox>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    void SetButtonStyleV(QPushButton *button, QString imgsrc, int CutSec);
    void SetButtonStyleH(QPushButton *button, QString imgsrc, int CutSec);
    QSound *mainsound;
    QSound *gamesound;
signals:

public slots:

};

#endif // MYWIDGET_H
