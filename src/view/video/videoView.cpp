#include "videoView.h"

VideoWidget::VideoWidget(QWidget* parent) : QWidget(parent) {
    viewfinder = new QCameraViewfinder(this);
    viewfinder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(viewfinder);
    setLayout(layout);
}

QCameraViewfinder* VideoWidget::getViewfinder() {
    return viewfinder;
}
