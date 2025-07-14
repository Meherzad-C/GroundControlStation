#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QCameraViewfinder>

#include "../../controller/video_source/videoController.h"

class VideoController;

class VideoView : public QWidget {
    Q_OBJECT

public:
    explicit VideoView(QWidget* parent = nullptr);
    QCameraViewfinder* getViewfinder();
    void startVideo();

private:
    VideoController* videoController;
    QCameraViewfinder* viewfinder;
};
