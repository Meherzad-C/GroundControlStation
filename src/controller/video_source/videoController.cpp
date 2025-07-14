#include "videoController.h"

VideoController::VideoController(VideoView* videoView, QObject* parent)
	: QObject(parent), videoModel(new VideoModel(this)), videoView(videoView) {
}

void VideoController::startVideo() {
	videoModel->getCamera()->setViewfinder(videoView->getViewfinder());
	videoModel->getCamera()->start();
}
