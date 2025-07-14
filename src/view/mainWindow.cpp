#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    // Central widget setup
    auto* central = new QWidget(this);
    auto* layout = new QHBoxLayout(central);
    layout->setContentsMargins(0, 0, 0, 0);

    // --- VIDEO SECTION (Left Panel) ---
    auto* videoViewContainer = new QWidget(this);
    auto* videoLayout = new QVBoxLayout(videoViewContainer);
    videoLayout->setContentsMargins(0, 0, 0, 0);

    // Live camera feed
    auto* cameraWidget = new VideoView(videoViewContainer);
    cameraWidget->startVideo();
    videoLayout->addWidget(cameraWidget);

    // File-based video playback
    auto* fileWidget = new FileVideoView(videoViewContainer);
    fileWidget->startPlayback((QStringLiteral("..\\..\\..\\resources\\videos\\video.mp4")));
    videoLayout->addWidget(fileWidget);

    videoLayout->setStretch(0, 1);  // Camera view
    videoLayout->setStretch(1, 1);  // File video

    videoViewContainer->setMinimumWidth(200);
    videoViewContainer->setMaximumWidth(600);
    videoViewContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // --- MAP VIEW (Right Panel) ---
    mapView = new MapView(this);

    // --- HORIZONTAL SPLITTER ---
    auto* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(videoViewContainer);
    mapView->show();
    splitter->addWidget(mapView);

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 2);
    splitter->setSizes({ width() / 3, (2 * width()) / 3 });

    layout->addWidget(splitter);
    central->setLayout(layout);
    setCentralWidget(central);

    showMaximized();
}