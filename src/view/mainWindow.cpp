#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    // Create central widget and layout
    auto* central = new QWidget(this);
    auto* layout = new QHBoxLayout(central);
    layout->setContentsMargins(0, 0, 0, 0);

    // --- VIDEO MVC ---
    videoView = new VideoView(this);
    videoView->startVideo();

    // Optional: Force reasonable size for video
    videoView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    videoView->setMinimumWidth(200);
    videoView->setMaximumWidth(600);  // Cap it if needed

    // --- MAP VIEW ---
    mapView = new MapView(this);

    // --- SPLITTER (VIDEO | MAP) ---
    auto* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(videoView);  // Index 0
    splitter->addWidget(mapView);    // Index 1

    splitter->setStretchFactor(0, 1); // video = 1
    splitter->setStretchFactor(1, 2); // map = 2

    // Enforce initial sizes manually (1/3, 2/3)
    splitter->setSizes({ width() / 3, (2 * width()) / 3 });

    layout->addWidget(splitter);
    central->setLayout(layout);
    setCentralWidget(central);

    showMaximized();
}