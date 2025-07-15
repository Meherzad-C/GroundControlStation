#include "videoFeedController.h"

VideoFeedController::VideoFeedController(VideoFeedView* videoFeedView, QObject* parent)
    : QObject(parent), m_videoFeedModel(new VideoFeedModel(this)), m_videoFeedView(videoFeedView) {
}

void VideoFeedController::startVideo() {
    m_videoFeedModel->getCaptureSession()->setCamera(m_videoFeedModel->getCamera());
    m_videoFeedModel->getCaptureSession()->setVideoOutput(m_videoFeedView->getVideoWidget());
    m_videoFeedModel->getCamera()->start();
}