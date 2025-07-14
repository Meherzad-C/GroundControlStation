#pragma once

#include <QObject>
#include "../../model/video_source/fileVideoModel.h"
#include "../../view/video/fileVideoView.h"

class FileVideoView;

class FileVideoController : public QObject {
    Q_OBJECT

public:
    explicit FileVideoController(FileVideoView* view, QObject* parent = nullptr);
    void playVideo(const QString& path);

private:
    FileVideoModel* videoModel;
    FileVideoView* view;
};
