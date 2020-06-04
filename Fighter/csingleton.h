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
    static CSingleton *GetData(QString name);//��ȡ�����������ݿ�����
    bool CheckUser(QString name,QString pwd);
    bool AddUser(QString name,QString pwd,QString question,QString anwser);
    static QString NowUserName;
    static int NowUserScore;
    static bool SoundEffectFlag;
private:
    CSingleton(QString name);//��ֹ���캯��
    static CSingleton *csingleton;//���������
    QSqlDatabase data;//���ݿ�����


};

#endif // CSINGLETON_H
