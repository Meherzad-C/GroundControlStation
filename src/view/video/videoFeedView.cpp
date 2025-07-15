#include "videoFeedView.h"

VideoFeedView::VideoFeedView(QWidget* parent) : QWidget(parent) {
    m_videoFeedController = new VideoFeedController(this, this);
    m_videoWidget = new QVideoWidget(this);  
    m_videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_videoWidget);
    setLayout(layout);
}

QVideoWidget* VideoFeedView::getVideoWidget() {
    return m_videoWidget;
}

void VideoFeedView::startVideo() {
    m_videoFeedController->startVideo();
}
