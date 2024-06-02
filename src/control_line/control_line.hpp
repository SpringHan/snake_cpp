#ifndef CONTROL_LINE
#define CONTROL_LINE

#include "qboxlayout.h"
#include "qpushbutton.h"
#include "qwidget.h"

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>

class ControlLine: public QWidget
{
	Q_OBJECT
	
public:
  ControlLine(QWidget *parent = nullptr);

private:
	QWidget *main_widget;
	QBoxLayout *main_layout;
	QPushButton *start_btn;
	QPushButton *pause_btn;
};

#endif
