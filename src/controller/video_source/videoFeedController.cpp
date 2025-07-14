#include "videoFeedController.h"

VideoFeedController::VideoFeedController(VideoFeedView* videoFeedView, QObject* parent)
	: QObject(parent), videoFeedModel(new VideoFeedModel(this)), videoFeedView(videoFeedView) {
}

void VideoFeedController::startVideo() {
	videoFeedModel->getCamera()->setViewfinder(videoFeedView->getViewfinder());
	videoFeedModel->getCamera()->start();
}
