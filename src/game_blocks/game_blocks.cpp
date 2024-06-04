#include "./game_blocks.hpp"

#include "qbrush.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qnamespace.h"
#include "qpainter.h"
#include "qwidget.h"
#include "qwindowdefs.h"

#include <QPixmap>
#include <QPainter>

GameBlocks::GameBlocks(QWidget *parent)
	:QWidget(parent)
{
	blocks = new QGraphicsScene(this);
	view = new QGraphicsView(blocks, this);
	
	QPixmap bg(30, 20);
	QPainter p(&bg);
	p.setBrush(Qt::cyan);
	p.drawRect(0, 0, 30, 20);
	
	view->setBackgroundBrush(QBrush(bg));
	blocks->addLine(0, 0, 50, 50);
}

void GameBlocks::resetSize(QSize size) {
	// QSize nsize = QSize(size.width() * 0.98, size.height() * 0.95);
	QSize nsize = size;

	QPixmap bg(size.width() / 30, size.height() / 20);
	QPainter p(&bg);
	p.setBrush(Qt::cyan);
	p.drawRect(0, 0, nsize.width(), nsize.height());

	view->setBackgroundBrush(QBrush(bg));
	view->resize(nsize);
	this->resize(nsize);
}
