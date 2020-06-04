#ifndef LAND_H
#define LAND_H

#include "mywidget.h"

class Land : public MyWidget
{
    Q_OBJECT
public:
    explicit Land(MyWidget *parent = 0);
    QLabel *LandLbl;
    QPushButton *LandBtn;
    QPushButton *ReturnBtn;
    QLineEdit *NameEdt;
    QLineEdit *PwdEdt;


signals:

public slots:
    void LandBtnClick();
    void ReturnBtnClick();

};

#endif // LAND_H
