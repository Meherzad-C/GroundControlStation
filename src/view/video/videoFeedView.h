#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QCameraViewfinder>

#include "../../controller/video_source/videoFeedController.h"

class VideoFeedController;

class VideoFeedView : public QWidget {
    Q_OBJECT

public:
    explicit VideoFeedView(QWidget* parent = nullptr);
    QCameraViewfinder* getViewfinder();
    void startVideo();

private:
    VideoFeedController* videoFeedController;
    QCameraViewfinder* viewfinder;
};
