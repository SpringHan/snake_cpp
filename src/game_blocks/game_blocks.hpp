#ifndef GAME_TABLES
#define GAME_TABLES

#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qobjectdefs.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class GameBlocks: public QWidget
{
	Q_OBJECT
public:
  GameBlocks(QWidget *parent = nullptr);
	void resetSize(QSize size);

private:
	QGraphicsScene *blocks;
	QGraphicsView *view;
};

#endif
