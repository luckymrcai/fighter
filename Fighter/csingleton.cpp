#include "csingleton.h"
#include <QDebug>

CSingleton *CSingleton::csingleton=NULL;//��̬��Ա������ʼ��
QString CSingleton::NowUserName=NULL;
int CSingleton::NowUserScore=0;
bool CSingleton::SoundEffectFlag=true;

CSingleton::CSingleton(QString name)
{
    //�������ݿ�����
    data=QSqlDatabase::addDatabase("QSQLITE");
    //�������ݿ�����
    data.setDatabaseName(name);
    //�����û���
    data.setUserName("root");
    //��������
    data.setPassword("123456");

    if(!data.open())
    {
        qDebug()<<"�����ݿ�ʧ��";
    }
    else
    {
        qDebug()<<"�����ݿ�ɹ�";
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
        qDebug()<<"�˺Ż����벻��Ϊ��"<<endl;
        return false;
    }
    else
    {
        QSqlQuery query;
        query.exec("select *from tbl_user where user_name ='"+name+"' ");
        query.first();

        if(query.value(0).toString()==NULL)
        {
            qDebug()<<"�û���������"<<endl;
            return false;
        }
        else
        {
            QString UserName=query.value(0).toString();
            QString UserPwd=query.value(1).toString();
            qDebug()<<QString("UserName=%1 UserPwd=%2 ").arg(UserName).arg(UserPwd);
            if(pwd!=UserPwd)
            {
                qDebug()<<"�������"<<endl;
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
        qDebug()<<"�û����Ѵ���"<<endl;
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


