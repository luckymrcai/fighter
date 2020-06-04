#include "widget_regist.h"

Widget_Regist::Widget_Regist(MyWidget *parent)
    :MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //���ñ���
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/login/cover.jpg").scaled(this->size())));
    this->setPalette(palette);

//    this->setWindowFlags(Qt::FramelessWindowHint);//���ر߿�

    //ע���
    RegistLbl=new QLabel(this);
    RegistLbl->setPixmap(QPixmap("img/image/login/login0001.png"));
    RegistLbl->setScaledContents(true);
    RegistLbl->setGeometry(42,100,RegistLbl->pixmap()->width(),RegistLbl->pixmap()->height());

    //��ť��ע��
    RegistBtn=new QPushButton(this);
    SetButtonStyleH(RegistBtn,"img/image/login/login005.png",2);
    RegistBtn->connect(RegistBtn,SIGNAL(clicked()),this,SLOT(RegistBtnClick()));

    //��ť������
    ReturnBtn=new QPushButton(this);
    SetButtonStyleH(ReturnBtn,"img/image/login/login007.png",2);
    ReturnBtn->connect(ReturnBtn,SIGNAL(clicked()),this,SLOT(ReturnBtnClick()));

    //ˮƽ���֣�ע�᷵�أ�
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(RegistBtn);
    hboxlayout->addWidget(ReturnBtn);
    hboxlayout->setContentsMargins(155,423,155,0);

    //�༭�����˺�
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(250,285,260,45);
    NameEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    NameEdt->setPlaceholderText("�������û���");//�û����༭����ʾ��Ϣ
    NameEdt->setMaxLength(6);//�޶����볤��
    QRegExp regexp("[A-Za-z0-9]{1,12}");//������������//ֻ����Ӣ�Ļ�������
//    NameEdt->setValidator(new QRegExpValidator(regexp,this));

    //�༭��������
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(250,350,260,45);
    PwdEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdEdt->setPlaceholderText("������6-8λ����");//����༭����ʾ��Ϣ
    PwdEdt->setMaxLength(8);//�޶����볤��
    PwdEdt->setEchoMode(QLineEdit::Password);//�����ʽ���ڵ���ʾ
    QRegExp regexppwd("[0-9]{1,8}");//�޶�����ֻ��������
    PwdEdt->setValidator(new QRegExpValidator(regexppwd,this));

    //�༭����ȷ������
    PwdSecondEdt=new QLineEdit(this);
    PwdSecondEdt->setGeometry(250,428,260,45);
    PwdSecondEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdSecondEdt->setPlaceholderText("������6-8λ����");//����༭����ʾ��Ϣ
    PwdSecondEdt->setMaxLength(8);//�޶����볤��
    PwdSecondEdt->setEchoMode(QLineEdit::Password);//�����ʽ���ڵ���ʾ
    PwdSecondEdt->setValidator(new QRegExpValidator(regexppwd,this));

    //�ܱ�����������
    QuestionBox=new QComboBox(this);
    QuestionBox->setGeometry(250,500,260,45);
    QuestionBox->setStyleSheet("background:transparent;color:white;");
    QuestionBox->addItem("��ѡ���ܱ�����");
    QuestionBox->addItem("���ĸ���������");
    QuestionBox->addItem("����ĸ��������");
    QuestionBox->addItem("����ѧ����");
    QuestionBox->addItem("�������л������");

    //�༭������
    ResultEdt=new QLineEdit(this);
    ResultEdt->setGeometry(250,563,260,45);
    ResultEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    ResultEdt->setPlaceholderText("�������ܱ���");//����༭����ʾ��Ϣ
    ResultEdt->setMaxLength(12);//�޶����볤��

    connect(NameEdt,SIGNAL(editingFinished()),this,SLOT(NameEdtFocus()));
}

void Widget_Regist::RegistBtnClick()
{
    CSingleton *UserImg=CSingleton::GetData("img/data.db");
    QString Name=NameEdt->text();
    QString Pwd=PwdEdt->text();
    QString Pwd_2=PwdSecondEdt->text();
    QString Question=QuestionBox->currentText();
    QString Anwser=ResultEdt->text();
    if(NameEdt->text()==NULL || PwdEdt->text()==NULL || PwdSecondEdt->text()==NULL)//�û�����Ϊ���ж�
    {
        QMessageBox::warning(this,"��ʾ","�û��������벻��Ϊ��",QMessageBox::Ok);
    }
    else if(QuestionBox->currentText()=="��ѡ���ܱ�����")//�ܱ�����ѡ���ж�
    {
        QMessageBox::warning(this,"��ʾ","��ѡ���ܱ�����",QMessageBox::Ok);
    }
    else if(ResultEdt->text()==NULL)//�ܱ��𰸲�Ϊ���ж�
    {
        QMessageBox::warning(this,"��ʾ","�ܱ��𰸲���Ϊ��",QMessageBox::Ok);
    }
    else if(PwdEdt->text().count()<6)//����λ���ж�
    {
        QMessageBox::warning(this,"��ʾ","������6λ��������",QMessageBox::Ok);
    }
    else if(PwdSecondEdt->text()!=PwdEdt->text())//�����Ƿ�һ���ж�
    {
        QMessageBox::warning(this,"��ʾ","���벻һ��",QMessageBox::Ok);
    }
    else
    {
        if(UserImg->AddUser(Name,Pwd,Question,Anwser))
        {
            QMessageBox::warning(this,"��ϲ","��ϲ�ɺأ�ע��ɹ���Ҫ�μ�����˺ź�����Ŷ��",QMessageBox::Ok);
            //�ı�����ϢҪ���
            NameEdt->clear();
            PwdEdt->clear();
            PwdSecondEdt->clear();
            ResultEdt->clear();
            QuestionBox->clear();
            QuestionBox->addItem("��ѡ���ܱ�����");
            QuestionBox->addItem("���ĸ���������");
            QuestionBox->addItem("����ĸ��������");
            QuestionBox->addItem("����������");
            QuestionBox->addItem("����������˭");
        }
        else
        {
            QMessageBox::warning(this,"��ʾ","����û���̫�����ˣ��Ѿ�����ȡ�ˣ������ٻ�һ���£�",QMessageBox::Ok);
        }
    }




}

void Widget_Regist::ReturnBtnClick()
{
    this->hide();
}

void Widget_Regist::NameEdtFocus()
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
        if(query.value(0).toString()!=NULL)
        {
            QMessageBox::warning(this,"��ʾ","���û����Ѵ���",QMessageBox::Ok);
        }

    }
}

