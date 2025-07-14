#pragma once

#include "../../model/video_source/videoModel.h"
#include "../../view/video/videoView.h"

class VideoView;

class VideoController : public QObject {
    Q_OBJECT
public:
    VideoController(VideoView* videoView, QObject* parent = nullptr);
    void startVideo();

private:
    VideoModel* videoModel;
    VideoView* videoView;
};
