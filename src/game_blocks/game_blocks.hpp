#ifndef GAME_TABLES
#define GAME_TABLES

#include "qboxlayout.h"
#include "qcolor.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qobjectdefs.h"
#include "qtableview.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QBoxLayout>
#include <QTableView>
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
