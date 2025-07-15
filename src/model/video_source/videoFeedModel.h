#pragma once

#include <QObject>
#include <QCamera>
#include <QMediaCaptureSession>

class VideoFeedModel : public QObject {
    Q_OBJECT

public:
    explicit VideoFeedModel(QObject* parent = nullptr);

    QCamera* getCamera();
    QMediaCaptureSession* getCaptureSession();

private:
    QCamera* m_camera;
    QMediaCaptureSession* m_captureSession;
};