#include "GroundControlStation.h"

GroundControlStation::GroundControlStation() {

}

int GroundControlStation::run(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
}