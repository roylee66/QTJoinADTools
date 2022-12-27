#include "Header.h"


#pragma execution_character_set("utf-8")

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // 构建这个主窗口的时候，把刚才的这个窗口初始化一下
    if (m_temp == NULL)
    {
        m_temp = new QtTempClass();// 这是初始化全局变量
    }
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}


void QtWidgetsApplication1::on_pushButton_clicked()
{
    m_temp->show();// 这样你每次调用的都是这一个窗口

    if (ui.pushButton_2->isCheckable()) {        //切换按钮状态
        ui.pushButton_2->setCheckable(false);
    }
    else {
        ui.pushButton_2->setCheckable(true);
    }

    if (ui.pushButton_2->isCheckable()) {        //切换按钮标签字
        ui.pushButton_2->setText("123");//启停按钮
    }
    else {
        ui.pushButton_2->setText("456");//点动按钮
    }
}
