#include "./game_tables.hpp"

#include "qtableview.h"
#include "qwidget.h"

GameBlocks::GameBlocks(QWidget *parent)
	:QWidget(parent)
{
	table = new QTableView(this);
}
