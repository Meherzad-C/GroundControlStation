#include "videoFileView.h"

VideoFileView::VideoFileView(QWidget* parent)
    : QWidget(parent),
    videoFeedController(new VideoFileController(this)),
    layout(new QVBoxLayout(this)) {
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
}

void VideoFileView::startPlayback(const QString& path) {
    videoFeedController->playVideo(path);
}

void VideoFileView::setVideoOutput(QVideoWidget* videoOutput) {
    layout->addWidget(videoOutput);
}
