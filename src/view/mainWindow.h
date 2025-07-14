#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QDir>
#include <QHBoxLayout>
#include <QSplitter>
#include <QWidget>

#include "map/mapView.h"
#include "video/videoFeedView.h"
#include "video/videoFileView.h"
//#include "../model/video_source/videoFeedModel.h"
//#include "../controller/video_source/videoFeedController.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

private:
    MapView* mapView;
    VideoFeedView* videoFeedView;
};

#endif // MAINWINDOW_H
