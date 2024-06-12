#ifndef GAME_TABLES
#define GAME_TABLES

#include <QWidget>

#include <QBoxLayout>
#include <QTableWidget>

class GameBlocks: public QWidget
{
	Q_OBJECT
public:
  GameBlocks(QWidget *parent = nullptr);
	void resetSize(QSize size);
	void changeItemColor(int idx, QColor color);

private:
	QTableWidget *table;

	void initTableSize(QSize size);
	void initTableItems();
};

#endif
