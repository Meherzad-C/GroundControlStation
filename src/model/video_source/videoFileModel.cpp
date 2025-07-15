#include "videoFileModel.h"

VideoFileModel::VideoFileModel(QObject* parent)
	: QObject(parent),
	m_mediaPlayer(new QMediaPlayer(this)),
	m_videoWidget(new QVideoWidget) {
	m_mediaPlayer->setVideoOutput(m_videoWidget);

	connect(m_mediaPlayer, &QMediaPlayer::mediaStatusChanged,
		this, &VideoFileModel::handleMediaStatusChanged);
}

QMediaPlayer* VideoFileModel::getMediaPlayer() {
	return m_mediaPlayer;
}

QVideoWidget* VideoFileModel::getVideoWidget() {
	return m_videoWidget;
}

void VideoFileModel::setSource(const QString& filePath) {
	m_mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
}

void VideoFileModel::play() {
	m_mediaPlayer->play();
}

void VideoFileModel::stop() {
	m_mediaPlayer->stop();
}

void VideoFileModel::handleMediaStatusChanged(QMediaPlayer::MediaStatus status) {
	if (status == QMediaPlayer::EndOfMedia) {
		m_mediaPlayer->setPosition(0);
		m_mediaPlayer->play();	// loop the video
	}
}
