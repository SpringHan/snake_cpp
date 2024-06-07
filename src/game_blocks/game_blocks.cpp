#include "./game_blocks.hpp"

#include "qabstractitemview.h"
#include "qboxlayout.h"
#include "qbrush.h"
#include "qcolor.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qheaderview.h"
#include "qnamespace.h"
#include "qpainter.h"
#include "qtablewidget.h"
#include "qwidget.h"
#include "qwindowdefs.h"

#include <sstream>

#include <QPixmap>
#include <QPainter>
#include <QHeaderView>

GameBlocks::GameBlocks(QWidget *parent)
	:QWidget(parent)
{
	this->setObjectName("GameBlocksWidget");

	// Table
	table = new QTableWidget(this);
	table->setColumnCount(25);
	table->setRowCount(15);

	table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	table->setSelectionMode(QAbstractItemView::NoSelection);

	table->setFocusPolicy(Qt::NoFocus);
	table->verticalHeader()->setVisible(false);
	table->horizontalHeader()->setVisible(false);
	table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	this->initTableItems();
}

void GameBlocks::resetSize(QSize size) {
	// QSize nsize = QSize(size.width() * 0.98, size.height() * 0.95);

	this->resize(size);
	table->resize(size);
	this->initTableSize(size);
}

void GameBlocks::initTableSize(QSize size) {
	int w = size.width() / 25;
	int remain = size.width() - w * 25;

	std::stringstream style;
	style << "QTableWidget { padding-left: " << (int)(remain / 2) << "px; }";

	table->setStyleSheet(QString::fromStdString(style.str()));

	for (int i = 0; i < 25; i++) {
		if (i < 15) {
			table->setRowHeight(i, w);
		}

		table->setColumnWidth(i, w);
	}
}

void GameBlocks::initTableItems() {
	for (int i = 0; i < 25 ; i++) {
		for (int j = 0; j < 15; j++) {
			table->setItem(i, j, new QTableWidgetItem);
		}
	}
}

void GameBlocks::changeItemColor(int idx, QColor color) {
	table->item(0, 0)->setBackground(color);
}
