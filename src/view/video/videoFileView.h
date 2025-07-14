#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QVideoWidget>

#include "../../controller/video_source/videoFileController.h"

class VideoFileController;
class QVideoWidget;

class VideoFileView : public QWidget {
    Q_OBJECT

public:
    explicit VideoFileView(QWidget* parent = nullptr);
    void startPlayback(const QString& path);
    void setVideoOutput(QVideoWidget* videoOutput);

private:
    VideoFileController* videoFeedController;
    QVBoxLayout* layout;
};
