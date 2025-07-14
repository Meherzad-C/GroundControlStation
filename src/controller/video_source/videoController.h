#pragma once

#include "../../model/video_source/videoModel.h"
#include "../../view/video/videoView.h"

class VideoController {
public:
    VideoController(VideoModel* model, VideoWidget* view);
    void startVideo();

private:
    VideoModel* model;
    VideoWidget* view;
};
