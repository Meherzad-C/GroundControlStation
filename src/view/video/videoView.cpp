#include "videoView.h"

VideoView::VideoView(QWidget* parent) : QWidget(parent) {
	videoController = new VideoController(this, this);
	viewfinder = new QCameraViewfinder(this);
	viewfinder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	auto layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(viewfinder);
	setLayout(layout);
}

QCameraViewfinder* VideoView::getViewfinder() {
	return viewfinder;
}

void VideoView::startVideo() {
	videoController->startVideo();
}
