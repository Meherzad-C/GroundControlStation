#include "videoModel.h"

VideoModel::VideoModel(QObject* parent)
    : QObject(parent)
{
    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder;
    camera->setViewfinder(viewfinder);
    camera->start();
}

QCamera* VideoModel::getCamera() { 
    return camera; 
}

QCameraViewfinder* VideoModel::getViewfinder() {
    return viewfinder; 
}
