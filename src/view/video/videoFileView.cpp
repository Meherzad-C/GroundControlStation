#include "videoFileView.h"

VideoFileView::VideoFileView(QWidget* parent)
    : QWidget(parent),
    m_videoFileController(new VideoFileController(this)),
    m_layout(new QVBoxLayout(this)) {
    m_layout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_layout);
}

void VideoFileView::startPlayback(const QString& path) {
    m_videoFileController->playVideo(path);
}

void VideoFileView::setVideoOutput(QVideoWidget* videoOutput) {
    m_layout->addWidget(videoOutput);
}