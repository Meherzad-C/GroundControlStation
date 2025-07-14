#include "videoController.h"

VideoController::VideoController(VideoModel* model, VideoWidget* view)
    : model(model), view(view) {}

void VideoController::startVideo() {
    model->getCamera()->setViewfinder(view->getViewfinder());
    model->getCamera()->start();
}
