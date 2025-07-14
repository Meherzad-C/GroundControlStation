#include "videoFeedModel.h"

VideoFeedModel::VideoFeedModel(QObject* parent)
    : QObject(parent)
{
    camera = new QCamera(this);
    viewfinder = new QCameraViewfinder;
    camera->setViewfinder(viewfinder);
    camera->start();
}

QCamera* VideoFeedModel::getCamera() { 
    return camera; 
}

QCameraViewfinder* VideoFeedModel::getViewfinder() {
    return viewfinder; 
}
