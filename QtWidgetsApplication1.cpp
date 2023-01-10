#pragma execution_character_set("utf-8")
#include "Header.h"
#include <QProcess>
#include <iostream>
#include <QTime>
#include <QtNetwork>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include<windows.h>


//QByteArray  m_text = "123456ABC";
//m_text = m_text.toBase64();//加密
//QByteArray::fromBase64(m_text)//解密

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);
    ver();
    ui.label_test->setText(QString::fromLocal8Bit("域账户:"));//lable定义文本
    iptest();


    
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
{
    // m_temp->show();// 这样你每次调用的都是这一个窗口

};

void QtWidgetsApplication1::on_pushButton_clicked()//计算机属性
{

    //system("ipconfig&pause"); //多行用&连接 system直接调用cmd窗口
    //system("sysdm.cpl");//系统属性
   // system("compmgmt.msc");//计算机属性

  /*  
    // 此方法堵塞线程
    QProcess compmgmt(0);
    compmgmt.start("cmd", QStringList() << "/c" << "compmgmt.msc");
    compmgmt.waitForStarted();
    compmgmt.waitForFinished();*/

    // 此方法为创建一个线程，并给它空间
    QProcess* process = new QProcess(this);
    process->start("cmd", QStringList() << "/c" << "compmgmt.msc");
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
    if (ui.lineEdit->text() != "")
    {
        QString yuzhanghao = ui.lineEdit->text();
 //       char* yuzhanghao_ch = yuzhanghao.toLatin1().data();
        QString strCmd = "net localgroup administrators " + yuzhanghao + " /add&pause";
       // const char* cCmd = strCmd.toStdString().c_str();
        system(strCmd.toStdString().c_str());//权限

       // system("net localgroup administrators " + ui.lineEdit->text()+" /add&pause");//权限
    }
    else{
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("用户名不能空."));//弹窗
        }
}
void QtWidgetsApplication1::on_pushButton_4_clicked()//pushbutton4按下 加域
{
        QString strCmd = "netdom join %computername% /domain:" + adadrrs + " /UserD : " + aduser + " /PasswordD : " + adpsw+"&pause"; //加域
        //// const char* cCmd = strCmd.toStdString().c_str();
        system(strCmd.toStdString().c_str());//权限
        //system("netdom join % computername % / domain:hf.huafangtec.cn / UserD : lilei-hj / PasswordD : ASD!@#123");//0
        //system("netdom join % computername % / domain:hf.huafangtec.cn / UserD : lilei-hj / PasswordD : ASD!@#123");//1
}
void QtWidgetsApplication1::on_pushButton_5_clicked()//pushbutton5按下 退域
{
    QString strCmd = "netdom join %computername% /domain:" + adadrrs + " /UserD : " + aduser + " /PasswordD : " + adpsw + "&pause"; //加域
    //// const char* cCmd = strCmd.toStdString().c_str();
    system(strCmd.toStdString().c_str());//权限
}
//void QtWidgetsApplication1::on_checkBox_stateChanged(int arg1)
//{
//    {
//        if (arg1 == Qt::Checked) // "选中"
//        {
//            // 置顶，this指当前的窗口
//            QtWidgetsApplication1::SetWindowPos(HWND(this->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
//        }
//        else                   // 未选中 - Qt::Unchecked
//        {
//            // 不置顶
//            QtWidgetsApplication1::SetWindowPos(HWND(this->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
//        }
//
//    }
//};

void QtWidgetsApplication1::on_pushButton_6_clicked()//CMD
{
    system("cd Tools&dir /b&echo.&echo.&cmd /k&");

};
void QtWidgetsApplication1::iptest()//备用文本
{
  
    ui.label_ip->setText("");//lable定义文本

};

void QtWidgetsApplication1::ver()////验证1
{
    QTimer timer;
    timer.setInterval(5000);  // 设置超时时间 5 秒
    timer.setSingleShot(true);  // 单次触发

    QEventLoop loop;
    QString strUrl = QString("http://81.70.220.2/ver");
    QNetworkRequest request(strUrl);

    QNetworkAccessManager m_netMngr;
    QNetworkReply* replyCheckMeeting = m_netMngr.get(request);

    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(replyCheckMeeting, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray netver = replyCheckMeeting->readAll();
    replyCheckMeeting->deleteLater();
    QString msg = netver;
    if (netver != "1")
    {
        if (msg == "")
        {
            QMessageBox::about(NULL, "Error", "Network is not connected. Please connect to the network.(21)     ");
            exit(0);
        }
        else
        {
            // QMessageBox::information(NULL, "Error", msg);
            QMessageBox::about(NULL, "Error", msg);
            exit(0);
        }

    }
        
};