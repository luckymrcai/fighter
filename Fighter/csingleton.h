#ifndef CSINGLETON_H
#define CSINGLETON_H

#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QString>
#include <QDebug>


class CSingleton
{
public:
    ~CSingleton();
    static CSingleton *GetData(QString name);//获取单例对象：数据库连接
    bool CheckUser(QString name,QString pwd);
    bool AddUser(QString name,QString pwd,QString question,QString anwser);
    static QString NowUserName;
    static int NowUserScore;
    static bool SoundEffectFlag;
private:
    CSingleton(QString name);//禁止构造函数
    static CSingleton *csingleton;//单例类对象
    QSqlDatabase data;//数据库连接


};

#endif // CSINGLETON_H
