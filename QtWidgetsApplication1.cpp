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
//m_text = m_text.toBase64();//����
//QByteArray::fromBase64(m_text)//����

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);
    ver();
    ui.label_test->setText(QString::fromLocal8Bit("���˻�:"));//lable�����ı�
    iptest();


    
    // ui.lineEdit->clear();//���
    // ui.lineEdit->setEchoMode(QLineEdit::Normal);//����ģʽNormal������ģʽPassword��������NoEcho��ʧȥ���������ģʽPassword
    // ui.lineEdit->setPlaceholderText("Normal");//ռλ�ַ�Normal

    // ������������ڵ�ʱ�򣬰Ѹղŵ�������ڳ�ʼ��һ��
    //if (m_temp == NULL)
    //{
    //    m_temp = new QtTempClass();// ���ǳ�ʼ��ȫ�ֱ���
    //}
};

QtWidgetsApplication1::~QtWidgetsApplication1()
{
    // m_temp->show();// ������ÿ�ε��õĶ�����һ������

};

void QtWidgetsApplication1::on_pushButton_clicked()//���������
{

    //system("ipconfig&pause"); //������&���� systemֱ�ӵ���cmd����
    //system("sysdm.cpl");//ϵͳ����
   // system("compmgmt.msc");//���������

  /*  
    // �˷��������߳�
    QProcess compmgmt(0);
    compmgmt.start("cmd", QStringList() << "/c" << "compmgmt.msc");
    compmgmt.waitForStarted();
    compmgmt.waitForFinished();*/

    // �˷���Ϊ����һ���̣߳��������ռ�
    QProcess* process = new QProcess(this);
    process->start("cmd", QStringList() << "/c" << "compmgmt.msc");
}   
void QtWidgetsApplication1::on_pushButton_2_clicked()//ϵͳ����
{
     //system("sysdm.cpl");//ϵͳ����
     //system("compmgmt.msc");//���������
    QProcess sysdm(0);
    sysdm.start("cmd", QStringList() << "/c" << "sysdm.cpl");
    sysdm.waitForStarted();
    sysdm.waitForFinished();
}
void QtWidgetsApplication1::on_pushButton_3_clicked()//pushbutton3 ����
{
    if (ui.lineEdit->text() != "")
    {
        QString yuzhanghao = ui.lineEdit->text();
 //       char* yuzhanghao_ch = yuzhanghao.toLatin1().data();
        QString strCmd = "net localgroup administrators " + yuzhanghao + " /add&pause";
       // const char* cCmd = strCmd.toStdString().c_str();
        system(strCmd.toStdString().c_str());//Ȩ��

       // system("net localgroup administrators " + ui.lineEdit->text()+" /add&pause");//Ȩ��
    }
    else{
        QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û������ܿ�."));//����
        }
}
void QtWidgetsApplication1::on_pushButton_4_clicked()//pushbutton4���� ����
{
        QString strCmd = "netdom join %computername% /domain:" + adadrrs + " /UserD : " + aduser + " /PasswordD : " + adpsw+"&pause"; //����
        //// const char* cCmd = strCmd.toStdString().c_str();
        system(strCmd.toStdString().c_str());//Ȩ��
        //system("netdom join % computername % / domain:hf.huafangtec.cn / UserD : lilei-hj / PasswordD : ASD!@#123");//0
        //system("netdom join % computername % / domain:hf.huafangtec.cn / UserD : lilei-hj / PasswordD : ASD!@#123");//1
}
void QtWidgetsApplication1::on_pushButton_5_clicked()//pushbutton5���� ����
{
    QString strCmd = "netdom join %computername% /domain:" + adadrrs + " /UserD : " + aduser + " /PasswordD : " + adpsw + "&pause"; //����
    //// const char* cCmd = strCmd.toStdString().c_str();
    system(strCmd.toStdString().c_str());//Ȩ��
}
//void QtWidgetsApplication1::on_checkBox_stateChanged(int arg1)
//{
//    {
//        if (arg1 == Qt::Checked) // "ѡ��"
//        {
//            // �ö���thisָ��ǰ�Ĵ���
//            QtWidgetsApplication1::SetWindowPos(HWND(this->winId()), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
//        }
//        else                   // δѡ�� - Qt::Unchecked
//        {
//            // ���ö�
//            QtWidgetsApplication1::SetWindowPos(HWND(this->winId()), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
//        }
//
//    }
//};

void QtWidgetsApplication1::on_pushButton_6_clicked()//CMD
{
    system("cd Tools&dir /b&echo.&echo.&cmd /k&");

};
void QtWidgetsApplication1::iptest()//�����ı�
{
  
    ui.label_ip->setText("");//lable�����ı�

};

void QtWidgetsApplication1::ver()////��֤1
{
    QTimer timer;
    timer.setInterval(5000);  // ���ó�ʱʱ�� 5 ��
    timer.setSingleShot(true);  // ���δ���

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