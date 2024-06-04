#include "./control_line.hpp"

#include "qboxlayout.h"
#include "qnamespace.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qwidget.h"

#include <iostream>

ControlLine::ControlLine(QWidget *parent)
	:QWidget(parent)
{
	main_layout = new QHBoxLayout;

	start_btn = new QPushButton("开始");
	pause_btn = new QPushButton("暂停");

	main_layout->addWidget(start_btn, 0, Qt::AlignLeft);
	main_layout->addWidget(pause_btn, 1, Qt::AlignRight);

	this->setLayout(main_layout);

	connect(start_btn, SIGNAL(clicked()), this, SLOT(printSize()));
}

void ControlLine::printSize() {
	std::cout << this->size().width() << std::endl;
}
