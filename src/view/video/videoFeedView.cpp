#include "videoFeedView.h"

VideoFeedView::VideoFeedView(QWidget* parent) : QWidget(parent) {
	videoFeedController = new VideoFeedController(this, this);
	viewfinder = new QCameraViewfinder(this);
	viewfinder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	auto layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(viewfinder);
	setLayout(layout);
}

QCameraViewfinder* VideoFeedView::getViewfinder() {
	return viewfinder;
}

void VideoFeedView::startVideo() {
	videoFeedController->startVideo();
}
