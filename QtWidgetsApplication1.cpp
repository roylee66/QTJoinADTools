#pragma execution_character_set("utf-8")
#include "Header.h"
#include <QProcess>
#include <iostream>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.label_test->setText(QString::fromLocal8Bit("���˻�:"));//lable�����ı�
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
{}

// m_temp->show();// ������ÿ�ε��õĶ�����һ������
void QtWidgetsApplication1::on_pushButton_clicked()//���������
{

    //system("ipconfig&pause"); //������&���� systemֱ�ӵ���cmd����
    //system("sysdm.cpl");//ϵͳ����
   // system("compmgmt.msc");//���������

    QProcess compmgmt(0);
    compmgmt.start("cmd", QStringList() << "/c" << "compmgmt.msc");
    compmgmt.waitForStarted();
    compmgmt.waitForFinished();
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
    //netdom join %computername% /domain:�� �� ���� �� �� /UserD:�� �� A�û��� �� �� /PasswordD:�� �� A���� //����
    // 
   // if (ui.lineEdit->text() = "");
   // {
   //     QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),"�û�������Ϊ��");//����
   // }
   // else()
   // {
        //��Ϣ��(ȡDOS�����ı�1(��net localgroup administrators �� �� �û��� �� �� / add��), 0, , )
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
        QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�û������ܿ�."));//����
        }
}

void QtWidgetsApplication1::on_pushButton_4_clicked()//pushbutton4����
{
    QProcess p(0);
    p.start("cmd", QStringList() << "/c" << "ping www.baidu.com");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp = QString::fromLocal8Bit(p.readAllStandardOutput());  //������

        QMessageBox testMassage;
        testMassage.setText(strTemp);
        testMassage.exec();
};

void QtWidgetsApplication1::on_pushButton_5_clicked()//pushbutton5����
{
    //ui.label_test->setText(ui.lineEdit->text());//lable�����ı�

    //QProcess process(this);
    //process.setProgram("cmd");
    //QStringList argument;
    //argument << "/c" << ui.lineEdit->text();
    //process.setArguments(argument);
    //process.start();
    //process.waitForStarted(); //�ȴ���������
    //process.waitForFinished();//�ȴ�����ر�
    //QString temp = QString::fromLocal8Bit(process.readAllStandardOutput()); //���������Ϣ
    //QMessageBox testMassage;
    //testMassage.setText(temp);
    //testMassage.exec();



    system("net localgroup administrators liujunjie-hj /add&pause");//Ȩ�޲���
};