#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QVideoWidget>  

#include "../../controller/video_source/videoFeedController.h"

class VideoFeedController;

class VideoFeedView : public QWidget {
    Q_OBJECT

public:
    explicit VideoFeedView(QWidget* parent = nullptr);
    QVideoWidget* getVideoWidget(); 
    void startVideo();

private:
    VideoFeedController* m_videoFeedController;
    QVideoWidget* m_videoWidget;
};
