#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "./src/control_line/control_line.hpp"
#include "./src/game_blocks/game_blocks.hpp"
#include "qwidget.h"

#include <QMainWindow>
#include <QTableView>
#include <QBoxLayout>
#include <QEvent>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	QWidget *main_widget;
	QVBoxLayout *whole;
	ControlLine *control_line;
	GameBlocks *blocks;

	void initControlLine();
	void initGameTables();

protected:
	void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_HPP
