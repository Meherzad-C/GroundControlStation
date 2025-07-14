#include "fileVideoModel.h"

FileVideoModel::FileVideoModel(QObject* parent)
	: QObject(parent),
	mediaPlayer(new QMediaPlayer(this)),
	videoWidget(new QVideoWidget) {
	mediaPlayer->setVideoOutput(videoWidget);

	connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged,
		this, &FileVideoModel::handleMediaStatusChanged);
}

QMediaPlayer* FileVideoModel::getMediaPlayer() {
	return mediaPlayer;
}

QVideoWidget* FileVideoModel::getVideoWidget() {
	return videoWidget;
}

void FileVideoModel::setSource(const QString& filePath) {
	mediaPlayer->setMedia(QUrl::fromLocalFile(filePath));
}

void FileVideoModel::play() {
	mediaPlayer->play();
}

void FileVideoModel::stop() {
	mediaPlayer->stop();
}

void FileVideoModel::handleMediaStatusChanged(QMediaPlayer::MediaStatus status) {
	if (status == QMediaPlayer::EndOfMedia) {
		mediaPlayer->setPosition(0);
		// loop the video
		mediaPlayer->play();
	}
}
