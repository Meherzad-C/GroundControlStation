#include "fileVideoController.h"

FileVideoController::FileVideoController(FileVideoView* view, QObject* parent)
    : QObject(parent), videoModel(new FileVideoModel(this)), view(view) {}

void FileVideoController::playVideo(const QString& path) {
    videoModel->setSource(path);
    view->setVideoOutput(videoModel->getVideoWidget());
    videoModel->play();
}
