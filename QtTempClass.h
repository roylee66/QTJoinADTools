#pragma once

#include <QWidget>
#include "ui_QtTempClass.h"

class QtTempClass : public QWidget
{
	Q_OBJECT

public:
	QtTempClass(QWidget *parent = nullptr);
	~QtTempClass();

private:
	Ui::QtTempClassClass ui;
};
