#include "videoFeedModel.h"

VideoFeedModel::VideoFeedModel(QObject* parent)
	: QObject(parent), m_camera(new QCamera(this)),
	m_captureSession(new QMediaCaptureSession(this)) {}

QCamera* VideoFeedModel::getCamera() {
	return m_camera;
}

QMediaCaptureSession* VideoFeedModel::getCaptureSession() {
	return m_captureSession;
}