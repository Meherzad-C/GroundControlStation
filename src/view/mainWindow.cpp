#include "mainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    auto* central = new QWidget(this);
    auto* layout  = new QHBoxLayout(central);
    layout->setContentsMargins(0,0,0,0);

    // Left Panel: Videos
    auto* videoPane = new QWidget(this);
    auto* vLayout   = new QVBoxLayout(videoPane);
    vLayout->setContentsMargins(0,0,0,0);

    m_videoFeedView = new VideoFeedView(videoPane);
    m_videoFeedView->startVideo();
    vLayout->addWidget(m_videoFeedView);

    auto* file = new VideoFileView(videoPane);
    file->startPlayback("../../../resources/videos/video.mp4");
    vLayout->addWidget(file);

    vLayout->setStretch(0,1);
    vLayout->setStretch(1,1);

    // Right Panel: Map/Telemetry View
    m_telemetryView = new TelemetryView(this);

    // Splitter 
    auto* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(videoPane);
    splitter->addWidget(m_telemetryView);
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,2);

    layout->addWidget(splitter);
    splitter->setSizes({ width() / 3, (2 * width()) / 3 });
    setCentralWidget(central);
    showMaximized();
}
