#include "qlabel.h"
#include "./src/game.hpp"

#include <iostream>

#include <QApplication>
#include <QLabel>

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	QLabel hello("Test");

	hello.show();
	return app.exec();

	// return 0;
}
