#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QCameraViewfinder>

class VideoWidget : public QWidget {
    Q_OBJECT

public:
    explicit VideoWidget(QWidget* parent = nullptr);
    QCameraViewfinder* getViewfinder();

private:
    QCameraViewfinder* viewfinder;
};
