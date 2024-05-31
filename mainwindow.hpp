#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "qlabel.h"
#include "qpushbutton.h"
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	QPushButton *button;
	QLabel *temp_text; 
};

#endif // MAINWINDOW_HPP
