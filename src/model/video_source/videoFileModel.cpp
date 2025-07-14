#include "videoFileModel.h"

VideoFileModel::VideoFileModel(QObject* parent)
	: QObject(parent),
	mediaPlayer(new QMediaPlayer(this)),
	videoWidget(new QVideoWidget) {
	mediaPlayer->setVideoOutput(videoWidget);

	connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged,
		this, &VideoFileModel::handleMediaStatusChanged);
}

QMediaPlayer* VideoFileModel::getMediaPlayer() {
	return mediaPlayer;
}

QVideoWidget* VideoFileModel::getVideoWidget() {
	return videoWidget;
}

void VideoFileModel::setSource(const QString& filePath) {
	mediaPlayer->setMedia(QUrl::fromLocalFile(filePath));
}

void VideoFileModel::play() {
	mediaPlayer->play();
}

void VideoFileModel::stop() {
	mediaPlayer->stop();
}

void VideoFileModel::handleMediaStatusChanged(QMediaPlayer::MediaStatus status) {
	if (status == QMediaPlayer::EndOfMedia) {
		mediaPlayer->setPosition(0);
		// loop the video
		mediaPlayer->play();
	}
}
