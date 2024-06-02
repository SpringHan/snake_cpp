#include "./control_line.hpp"

#include "qboxlayout.h"
#include "qnamespace.h"
#include "qpushbutton.h"
#include "qwidget.h"

ControlLine::ControlLine(QWidget *parent)
	:QWidget(parent)
{
	main_widget = new QWidget(this);
	main_layout = new QHBoxLayout;

	start_btn = new QPushButton("开始");
	pause_btn = new QPushButton("暂停");

	main_layout->addWidget(start_btn, 0, Qt::AlignLeft);
	main_layout->addWidget(pause_btn, 1, Qt::AlignRight);

	main_widget->setLayout(main_layout);
}
