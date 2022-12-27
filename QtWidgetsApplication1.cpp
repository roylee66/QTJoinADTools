#pragma execution_character_set("utf-8")
#include "Header.h"
#include <QProcess>
#include <iostream>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.label_test->setText(QString::fromLocal8Bit("域账户:"));//lable定义文本
    // ui.lineEdit->clear();//清空
    // ui.lineEdit->setEchoMode(QLineEdit::Normal);//正常模式Normal；密码模式Password；不回显NoEcho；失去焦点变密码模式Password
    // ui.lineEdit->setPlaceholderText("Normal");//占位字符Normal

    // 构建这个主窗口的时候，把刚才的这个窗口初始化一下
    //if (m_temp == NULL)
    //{
    //    m_temp = new QtTempClass();// 这是初始化全局变量
    //}
};



QtWidgetsApplication1::~QtWidgetsApplication1()
{}

// m_temp->show();// 这样你每次调用的都是这一个窗口
void QtWidgetsApplication1::on_pushButton_clicked()//计算机属性
{

    //system("ipconfig&pause"); //多行用&连接 system直接调用cmd窗口
    //system("sysdm.cpl");//系统属性
   // system("compmgmt.msc");//计算机属性

    QProcess compmgmt(0);
    compmgmt.start("cmd", QStringList() << "/c" << "compmgmt.msc");
    compmgmt.waitForStarted();
    compmgmt.waitForFinished();
}   

void QtWidgetsApplication1::on_pushButton_2_clicked()//系统属性
{
     //system("sysdm.cpl");//系统属性
     //system("compmgmt.msc");//计算机属性
    QProcess sysdm(0);
    sysdm.start("cmd", QStringList() << "/c" << "sysdm.cpl");
    sysdm.waitForStarted();
    sysdm.waitForFinished();
}

void QtWidgetsApplication1::on_pushButton_3_clicked()//pushbutton3 加组
{
    //netdom join %computername% /domain:” ＋ 域名 ＋ “ /UserD:” ＋ A用户名 ＋ “ /PasswordD:” ＋ A密码 //加域
    // 
   // if (ui.lineEdit->text() = "");
   // {
   //     QMessageBox::information(this, QString::fromLocal8Bit("提示"),"用户名不能为空");//弹窗
   // }
   // else()
   // {
        //信息框(取DOS返回文本1(“net localgroup administrators ” ＋ 用户名 ＋ “ / add”), 0, , )
    //};

    if (ui.lineEdit->text() != "")
    { 
        QProcess net(0);
        net.start("cmd", QStringList() << "/c net localgroup administrators " + ui.lineEdit->text() + " / add");
        net.waitForStarted();
        net.waitForFinished();
        QString strTemp = QString::fromLocal8Bit(net.readAllStandardOutput());

        QMessageBox testMassage;
        testMassage.setText(strTemp);
        testMassage.exec();
    }
    else{
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名不能空."));//弹窗
        }
}

void QtWidgetsApplication1::on_pushButton_4_clicked()//pushbutton4按下
{
    QProcess p(0);
    p.start("cmd", QStringList() << "/c" << "ping www.baidu.com");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp = QString::fromLocal8Bit(p.readAllStandardOutput());  //获得输出

        QMessageBox testMassage;
        testMassage.setText(strTemp);
        testMassage.exec();
};

void QtWidgetsApplication1::on_pushButton_5_clicked()//pushbutton5按下
{
    //ui.label_test->setText(ui.lineEdit->text());//lable定义文本

    //QProcess process(this);
    //process.setProgram("cmd");
    //QStringList argument;
    //argument << "/c" << ui.lineEdit->text();
    //process.setArguments(argument);
    //process.start();
    //process.waitForStarted(); //等待程序启动
    //process.waitForFinished();//等待程序关闭
    //QString temp = QString::fromLocal8Bit(process.readAllStandardOutput()); //程序输出信息
    //QMessageBox testMassage;
    //testMassage.setText(temp);
    //testMassage.exec();



    system("net localgroup administrators liujunjie-hj /add&pause");//权限不足
};