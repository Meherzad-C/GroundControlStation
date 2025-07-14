#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include <QHBoxLayout>
#include <QSplitter>
#include <QWidget>

#include "map/mapView.h"
#include "video/videoView.h"
#include "../model/video_source/videoModel.h"
#include "../controller/video_source/videoController.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

private:
    MapView* mapView;
};

#endif // MAINWINDOW_H
