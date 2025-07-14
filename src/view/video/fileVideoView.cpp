#include "fileVideoView.h"

FileVideoView::FileVideoView(QWidget* parent)
    : QWidget(parent),
    videoController(new FileVideoController(this)),
    layout(new QVBoxLayout(this)) {
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void FileVideoView::startPlayback(const QString& path) {
    videoController->playVideo(path);
}

void FileVideoView::setVideoOutput(QVideoWidget* videoOutput) {
    layout->addWidget(videoOutput);
}
