#pragma once

#include <QObject>
#include "../../model/video_source/videoFileModel.h"
#include "../../view/video/videoFileView.h"

class VideoFileView;

class VideoFileController : public QObject {
    Q_OBJECT

public:
    explicit VideoFileController(VideoFileView* videoFileView, QObject* parent = nullptr);
    void playVideo(const QString& path);

private:
    VideoFileModel* videoFeedModel;
    VideoFileView* videoFileView;
};
