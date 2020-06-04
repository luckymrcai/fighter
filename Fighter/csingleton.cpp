#include "csingleton.h"
#include <QDebug>

CSingleton *CSingleton::csingleton=NULL;//静态成员变量初始化
QString CSingleton::NowUserName=NULL;
int CSingleton::NowUserScore=0;
bool CSingleton::SoundEffectFlag=true;

CSingleton::CSingleton(QString name)
{
    //创建数据库连接
    data=QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    data.setDatabaseName(name);
    //设置用户名
    data.setUserName("root");
    //设置密码
    data.setPassword("123456");

    if(!data.open())
    {
        qDebug()<<"打开数据库失败";
    }
    else
    {
        qDebug()<<"打开数据库成功";
    }

}

CSingleton *CSingleton::GetData(QString name)
{
    if(CSingleton::csingleton==NULL)
    {
        CSingleton::csingleton=new CSingleton(name);
    }

    return CSingleton::csingleton;
}

bool CSingleton::CheckUser(QString name,QString pwd)
{
    if(name==NULL || pwd==NULL)
    {
        qDebug()<<"账号或密码不能为空"<<endl;
        return false;
    }
    else
    {
        QSqlQuery query;
        query.exec("select *from tbl_user where user_name ='"+name+"' ");
        query.first();

        if(query.value(0).toString()==NULL)
        {
            qDebug()<<"用户名不存在"<<endl;
            return false;
        }
        else
        {
            QString UserName=query.value(0).toString();
            QString UserPwd=query.value(1).toString();
            qDebug()<<QString("UserName=%1 UserPwd=%2 ").arg(UserName).arg(UserPwd);
            if(pwd!=UserPwd)
            {
                qDebug()<<"密码错误"<<endl;
                return false;
            }
            else
            {
                NowUserName=UserName;
                return true;
            }
        }
    }
}

bool CSingleton::AddUser(QString name,QString pwd,QString question,QString anwser)
{
    QSqlQuery query;
    query.exec("select *from tbl_user where user_name ='"+name+"' ");
    query.first();
    if(query.value(0).toString()!=NULL)
    {
        qDebug()<<"用户名已存在"<<endl;
        return false;
    }
    else
    {
        query.exec("insert into tbl_user values('"+name+"','"+pwd+"','"+question+"','"+anwser+"')");
        query.exec("insert into tbl_score values('"+name+"','0','0')");
        qDebug()<<"888";
        return true;
    }
}


