#pragma once

#include <QObject>
#include <QCamera>
#include <QCameraViewfinder>

class VideoModel : public QObject {
    Q_OBJECT

public:
    explicit VideoModel(QObject* parent = nullptr);
    QCamera* getCamera();
    QCameraViewfinder* getViewfinder();

private:
    QCamera* camera;
    QCameraViewfinder* viewfinder;
};
