#include "widget_password.h"

Widget_Password::Widget_Password(MyWidget *parent)
    :MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //���ñ���
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/login/cover.jpg").scaled(this->size())));
    this->setPalette(palette);

//    this->setWindowFlags(Qt::FramelessWindowHint);//���ر߿�

    //�һ������
    PasswordLbl=new QLabel(this);
    PasswordLbl->setPixmap(QPixmap("img/image/login/login0002.png"));
    PasswordLbl->setScaledContents(true);
    PasswordLbl->setGeometry(42,210,PasswordLbl->pixmap()->width(),PasswordLbl->pixmap()->height());

    //��ť��ȷ��
    YesBtn=new QPushButton(this);
    SetButtonStyleH(YesBtn,"img/image/login/uit0010 -1.png",2);
    YesBtn->connect(YesBtn,SIGNAL(clicked()),this,SLOT(YesBtnClick()));

    //��ť��ȡ��
    NoBtn=new QPushButton(this);
    SetButtonStyleH(NoBtn,"img/image/login/uit0009 - 1.png",2);
    NoBtn->connect(NoBtn,SIGNAL(clicked()),this,SLOT(NoBtnClick()));

    //ˮƽ���֣�ȷ��ȡ����
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(YesBtn);
    hboxlayout->addWidget(NoBtn);
    hboxlayout->setContentsMargins(160,270,160,0);

    //�༭�����˺�
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(250,285,260,45);
    NameEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    NameEdt->setPlaceholderText("�������û���");//�û����༭����ʾ��Ϣ
    NameEdt->setMaxLength(12);//�޶����볤��
    QRegExp regexp("[A-Za-z0-9]{1,12}");//������������//ֻ����Ӣ�Ļ�������
//    NameEdt->setValidator(new QRegExpValidator(regexp,this));

    //�ܱ�����
    QuestionLbl=new QLabel(this);
    QuestionLbl->setGeometry(250,360,260,45);
    QuestionLbl->setStyleSheet("background:transparent;border:0px;color:white;font-size: 25px;");


    //�༭������
    ResultEdt=new QLineEdit(this);
    ResultEdt->setGeometry(250,428,260,45);
    ResultEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    ResultEdt->setPlaceholderText("�������ܱ���");//�ܱ�����ʾ��Ϣ
    ResultEdt->setMaxLength(12);//�޶����볤��


    //�༭��������
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(250,500,260,45);
    PwdEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdEdt->setPlaceholderText("������6-8λ����");//����༭����ʾ��Ϣ
    PwdEdt->setMaxLength(8);//�޶����볤��
    PwdEdt->setEchoMode(QLineEdit::Password);//�����ʽ���ڵ���ʾ
    QRegExp regexppwd("[0-9]{1,8}");//�޶�����ֻ��������
    PwdEdt->setValidator(new QRegExpValidator(regexppwd,this));


    connect(NameEdt,SIGNAL(editingFinished()),this,SLOT(NameEdtFocus()));

}

void Widget_Password::YesBtnClick()
{

    QString Name=NameEdt->text();
    QString Answer=ResultEdt->text();
    QString Pwd=PwdEdt->text();
    if(NameEdt->text()==NULL)//�û�����Ϊ���ж�
    {
        QMessageBox::warning(this,"��ʾ","�������û���",QMessageBox::Ok);
    }
    else
    {


        if(PwdEdt->text().count()<6)//����λ���ж�
        {
            QMessageBox::warning(this,"��ʾ","������6λ��������",QMessageBox::Ok);
        }
        else
        {
            if(Answer==UserAnswer)
            {
                qDebug()<<"666";
                CSingleton *UserImg=CSingleton::GetData("img/data.db");
                QSqlQuery query;
                query.exec("update tbl_user set password='"+Pwd+"' where user_name ='"+Name+"'");
                QMessageBox::information(this,"��Ϣ","�޸ĳɹ�",QMessageBox::Ok);

            }
            else
            {
                QMessageBox::warning(this,"��ʾ","�ܱ��𰸴���",QMessageBox::Ok);
            }
        }

    }

}

void Widget_Password::NoBtnClick()
{
    this->hide();
}

void Widget_Password::NameEdtFocus()
{
    QString Name=NameEdt->text();
    if(NameEdt->text()==NULL)//�û�����Ϊ���ж�
    {
        QMessageBox::warning(this,"��ʾ","�������û���",QMessageBox::Ok);
    }
    else
    {
        CSingleton *UserImg=CSingleton::GetData("img/data.db");
        QSqlQuery query;
        query.exec("select *from tbl_user where user_name ='"+Name+"' ");
        query.first();
        if(query.value(0).toString()==NULL)
        {
            qDebug()<<"������"<<endl;
            QMessageBox::warning(this,"��ʾ","���û���������",QMessageBox::Ok);
        }
        else
        {
    //        query.exec("insert into tbl_user values('"+name+"','"+pwd+"','"+question+"','"+anwser+"')");
            qDebug()<<query.value(2);
            QString Question=query.value(2).toString();
            QuestionLbl->setText(Question);
            UserAnswer=query.value(3).toString();
        }
    }
}

