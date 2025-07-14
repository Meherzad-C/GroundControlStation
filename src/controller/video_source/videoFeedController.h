#pragma once

#include "../../model/video_source/videoFeedModel.h"
#include "../../view/video/videoFeedView.h"

class VideoFeedView;

class VideoFeedController : public QObject {
    Q_OBJECT
public:
    VideoFeedController(VideoFeedView* videoFeedView, QObject* parent = nullptr);
    void startVideo();

private:
    VideoFeedModel* videoFeedModel;
    VideoFeedView* videoFeedView;
};
