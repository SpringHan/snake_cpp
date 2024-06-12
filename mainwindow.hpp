#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "./src/control_line/control_line.hpp"
#include "./src/game_blocks/game_blocks.hpp"
#include "./src/game/game.hpp"

#include <QMainWindow>
#include <QTableView>
#include <QBoxLayout>
#include <QEvent>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	friend class Snake;

private:
	QWidget *main_widget;
	QVBoxLayout *whole;
	ControlLine *control_line;
	GameBlocks *blocks;
	Game *game;

protected:
	void resizeEvent(QResizeEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
};

#endif // MAINWINDOW_HPP
