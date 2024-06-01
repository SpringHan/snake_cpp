#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "qboxlayout.h"
#include "qlabel.h"
#include "qobjectdefs.h"
#include "qpushbutton.h"
#include "qtableview.h"
#include <QMainWindow>

#include <QLabel>
#include <QPushButton>
#include <QTableView>
#include <QBoxLayout>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	QWidget *main_widget;
	QVBoxLayout *whole;
	QHBoxLayout *control_line;
	QPushButton *start_btn;
	QPushButton *pause_btn;
	QTableView *blocks_table;

// private slots:
// 	void changeText();
};

#endif // MAINWINDOW_HPP
