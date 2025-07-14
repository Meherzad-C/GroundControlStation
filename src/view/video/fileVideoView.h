#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QVideoWidget>

#include "../../controller/video_source/fileVideoController.h"

class FileVideoController;
class QVideoWidget;

class FileVideoView : public QWidget {
    Q_OBJECT

public:
    explicit FileVideoView(QWidget* parent = nullptr);
    void startPlayback(const QString& path);
    void setVideoOutput(QVideoWidget* videoOutput);

private:
    FileVideoController* videoController;
    QVBoxLayout* layout;
};
