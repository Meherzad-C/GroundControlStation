#include "videoFileController.h"

VideoFileController::VideoFileController(VideoFileView* videoFileView, QObject* parent)
    : QObject(parent),
    m_videoFileModel(new VideoFileModel(this)),
    m_videoFileView(videoFileView) {}

void VideoFileController::playVideo(const QString& path) {
    m_videoFileModel->setSource(path);
    m_videoFileView->setVideoOutput(m_videoFileModel->getVideoWidget());
    m_videoFileModel->play();
}