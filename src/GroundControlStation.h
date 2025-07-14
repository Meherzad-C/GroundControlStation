#pragma once

#include "view/mainWindow.h"
#include <QApplication>

class GroundControlStation {
public:
	GroundControlStation();
	int run(int argc, char* argv[]);
};