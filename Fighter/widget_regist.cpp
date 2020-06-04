#include "widget_regist.h"

Widget_Regist::Widget_Regist(MyWidget *parent)
    :MyWidget(parent)
{
    this->setFixedSize(640,950);
    this->setAutoFillBackground(true);

    //设置背景
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/image/login/cover.jpg").scaled(this->size())));
    this->setPalette(palette);

//    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏边框

    //注册框
    RegistLbl=new QLabel(this);
    RegistLbl->setPixmap(QPixmap("img/image/login/login0001.png"));
    RegistLbl->setScaledContents(true);
    RegistLbl->setGeometry(42,100,RegistLbl->pixmap()->width(),RegistLbl->pixmap()->height());

    //按钮：注册
    RegistBtn=new QPushButton(this);
    SetButtonStyleH(RegistBtn,"img/image/login/login005.png",2);
    RegistBtn->connect(RegistBtn,SIGNAL(clicked()),this,SLOT(RegistBtnClick()));

    //按钮：返回
    ReturnBtn=new QPushButton(this);
    SetButtonStyleH(ReturnBtn,"img/image/login/login007.png",2);
    ReturnBtn->connect(ReturnBtn,SIGNAL(clicked()),this,SLOT(ReturnBtnClick()));

    //水平布局（注册返回）
    QHBoxLayout *hboxlayout=new QHBoxLayout(this);
    hboxlayout->addWidget(RegistBtn);
    hboxlayout->addWidget(ReturnBtn);
    hboxlayout->setContentsMargins(155,423,155,0);

    //编辑条：账号
    NameEdt=new QLineEdit(this);
    NameEdt->setGeometry(250,285,260,45);
    NameEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    NameEdt->setPlaceholderText("请输入用户名");//用户名编辑框提示信息
    NameEdt->setMaxLength(6);//限定输入长度
    QRegExp regexp("[A-Za-z0-9]{1,12}");//输入类型限制//只能是英文或者数字
//    NameEdt->setValidator(new QRegExpValidator(regexp,this));

    //编辑条：密码
    PwdEdt=new QLineEdit(this);
    PwdEdt->setGeometry(250,350,260,45);
    PwdEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdEdt->setPlaceholderText("请输入6-8位数字");//密码编辑框提示信息
    PwdEdt->setMaxLength(8);//限定输入长度
    PwdEdt->setEchoMode(QLineEdit::Password);//密码格式，黑点显示
    QRegExp regexppwd("[0-9]{1,8}");//限定密码只能是数字
    PwdEdt->setValidator(new QRegExpValidator(regexppwd,this));

    //编辑条：确认密码
    PwdSecondEdt=new QLineEdit(this);
    PwdSecondEdt->setGeometry(250,428,260,45);
    PwdSecondEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    PwdSecondEdt->setPlaceholderText("请输入6-8位数字");//密码编辑框提示信息
    PwdSecondEdt->setMaxLength(8);//限定输入长度
    PwdSecondEdt->setEchoMode(QLineEdit::Password);//密码格式，黑点显示
    PwdSecondEdt->setValidator(new QRegExpValidator(regexppwd,this));

    //密保问题下拉框
    QuestionBox=new QComboBox(this);
    QuestionBox->setGeometry(250,500,260,45);
    QuestionBox->setStyleSheet("background:transparent;color:white;");
    QuestionBox->addItem("请选择密保问题");
    QuestionBox->addItem("您的父亲姓名是");
    QuestionBox->addItem("您的母亲姓名是");
    QuestionBox->addItem("您的学号是");
    QuestionBox->addItem("您最想感谢的人是");

    //编辑条：答案
    ResultEdt=new QLineEdit(this);
    ResultEdt->setGeometry(250,563,260,45);
    ResultEdt->setStyleSheet("background:transparent;border:0px;color:white;");
    ResultEdt->setPlaceholderText("请输入密保答案");//密码编辑框提示信息
    ResultEdt->setMaxLength(12);//限定输入长度

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
    if(NameEdt->text()==NULL || PwdEdt->text()==NULL || PwdSecondEdt->text()==NULL)//用户名不为空判断
    {
        QMessageBox::warning(this,"提示","用户名或密码不能为空",QMessageBox::Ok);
    }
    else if(QuestionBox->currentText()=="请选择密保问题")//密保问题选择判断
    {
        QMessageBox::warning(this,"提示","请选择密保问题",QMessageBox::Ok);
    }
    else if(ResultEdt->text()==NULL)//密保答案不为空判断
    {
        QMessageBox::warning(this,"提示","密保答案不能为空",QMessageBox::Ok);
    }
    else if(PwdEdt->text().count()<6)//密码位数判断
    {
        QMessageBox::warning(this,"提示","密码需6位数及以上",QMessageBox::Ok);
    }
    else if(PwdSecondEdt->text()!=PwdEdt->text())//密码是否一致判断
    {
        QMessageBox::warning(this,"提示","密码不一致",QMessageBox::Ok);
    }
    else
    {
        if(UserImg->AddUser(Name,Pwd,Question,Anwser))
        {
            QMessageBox::warning(this,"恭喜","可喜可贺，注册成功，要牢记你的账号和密码哦！",QMessageBox::Ok);
            //文本框信息要清空
            NameEdt->clear();
            PwdEdt->clear();
            PwdSecondEdt->clear();
            ResultEdt->clear();
            QuestionBox->clear();
            QuestionBox->addItem("请选择密保问题");
            QuestionBox->addItem("您的父亲姓名是");
            QuestionBox->addItem("您的母亲姓名是");
            QuestionBox->addItem("您出生地是");
            QuestionBox->addItem("您经常想起谁");
        }
        else
        {
            QMessageBox::warning(this,"提示","这个用户名太好听了，已经被人取了，咱们再换一个呗！",QMessageBox::Ok);
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
    if(NameEdt->text()==NULL)//用户名不为空判断
    {
        QMessageBox::warning(this,"提示","请输入用户名",QMessageBox::Ok);
    }
    else
    {
        CSingleton *UserImg=CSingleton::GetData("img/data.db");
        QSqlQuery query;
        query.exec("select *from tbl_user where user_name ='"+Name+"' ");
        query.first();
        if(query.value(0).toString()!=NULL)
        {
            QMessageBox::warning(this,"提示","该用户名已存在",QMessageBox::Ok);
        }

    }
}

