#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    mapView = new MapView(this);
    setCentralWidget(mapView);

    showMaximized();
}

MainWindow::~MainWindow() = default;