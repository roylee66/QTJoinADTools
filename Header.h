#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ui.h"
#include "QtTempClass.h" 
#include "qmessagebox.h"
#include "qcheckbox.h"


#pragma execution_character_set("utf-8") // ��Ӵ��ļ���ֹ����

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

    //QtTempClass* m_temp = NULL; // ����������ͷ�ļ�����߶���һ��ȫ�ֱ��������ȫ�ֱ����ȸ���һ��NULL��֤�����Ǹ���ֵ

    QString adadrrs = "hf.huafangtec.cn";
    QString aduser = "lilei-hj";
    QString adpsw = "woshililei4613@";
    QString lver = NULL;

public slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    //void on_checkBox_stateChanged(int arg1);
    void iptest();
    void ver();

private:
    Ui::QtWidgetsApplication1Class ui;

};

