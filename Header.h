#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Ui.h"
#include "QtTempClass.h" //������

#pragma execution_character_set("utf-8") // ��Ӵ��ļ���ֹ����

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

    QtTempClass* m_temp = NULL; // ����������ͷ�ļ�����߶���һ��ȫ�ֱ��������ȫ�ֱ����ȸ���һ��NULL��֤�����Ǹ���ֵ
public slots:
    void on_pushButton_clicked();

private:
    Ui::QtWidgetsApplication1Class ui;
};

