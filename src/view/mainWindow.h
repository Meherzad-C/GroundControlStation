#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QDir>
#include <QHBoxLayout>
#include <QSplitter>
#include <QWidget>

#include "video/videoFeedView.h"
#include "video/videoFileView.h"
#include "telemetry/telemetryView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

private:
    VideoFeedView* m_videoFeedView;
    TelemetryView* m_telemetryView;
};
