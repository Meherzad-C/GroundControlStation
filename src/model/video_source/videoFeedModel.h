#pragma once

#include <QObject>
#include <QCamera>
#include <QCameraViewfinder>

class VideoFeedModel : public QObject {
    Q_OBJECT

public:
    explicit VideoFeedModel(QObject* parent = nullptr);
    QCamera* getCamera();
    QCameraViewfinder* getViewfinder();

private:
    QCamera* camera;
    QCameraViewfinder* viewfinder;
};
