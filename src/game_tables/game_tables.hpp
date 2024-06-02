#ifndef GAME_TABLES
#define GAME_TABLES

#include "qobjectdefs.h"
#include "qtableview.h"

#include <QWidget>
#include <QTableView>

class GameBlocks: public QWidget
{
	Q_OBJECT
public:
  GameBlocks(QWidget *parent = nullptr);

private:
	QTableView *table;
};

#endif
