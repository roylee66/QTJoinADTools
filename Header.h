#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ui.h"
#include "QtTempClass.h" 
#include "qmessagebox.h"

#pragma execution_character_set("utf-8") // 添加此文件防止乱码

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

    QtTempClass* m_temp = NULL; // 上面引用完头文件，这边定义一个全局变量，这个全局变量先给他一个NULL，证明他是个空值

    QString Username = "hf.huafangtec.cn";

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::QtWidgetsApplication1Class ui;
};

