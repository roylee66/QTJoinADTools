#include "Header.h"


#pragma execution_character_set("utf-8")

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // ������������ڵ�ʱ�򣬰Ѹղŵ�������ڳ�ʼ��һ��
    if (m_temp == NULL)
    {
        m_temp = new QtTempClass();// ���ǳ�ʼ��ȫ�ֱ���
    }
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}


void QtWidgetsApplication1::on_pushButton_clicked()
{
    m_temp->show();// ������ÿ�ε��õĶ�����һ������

    if (ui.pushButton_2->isCheckable()) {        //�л���ť״̬
        ui.pushButton_2->setCheckable(false);
    }
    else {
        ui.pushButton_2->setCheckable(true);
    }

    if (ui.pushButton_2->isCheckable()) {        //�л���ť��ǩ��
        ui.pushButton_2->setText("123");//��ͣ��ť
    }
    else {
        ui.pushButton_2->setText("456");//�㶯��ť
    }
}
