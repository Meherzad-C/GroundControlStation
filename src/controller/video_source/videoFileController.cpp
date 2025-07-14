#include "videoFileController.h"

VideoFileController::VideoFileController(VideoFileView* videoFileView, QObject* parent)
    : QObject(parent), videoFeedModel(new VideoFileModel(this)), videoFileView(videoFileView) {}

void VideoFileController::playVideo(const QString& path) {
    videoFeedModel->setSource(path);
    videoFileView->setVideoOutput(videoFeedModel->getVideoWidget());
    videoFeedModel->play();
}
