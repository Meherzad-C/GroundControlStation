#include "mapView.h"

MapView::MapView(QWidget* parent) : QWidget(parent)
{
    quickWidget = new QQuickWidget(this);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setSource(QUrl(QStringLiteral("qrc:/qml/maps/mapView.qml")));
    //quickWidget->setSource(QUrl::fromLocalFile("C:\\Users\\ltxme\\Desktop\\Other\\HW\\GroundControlStation\\resources\\qml\\maps\\mapView.qml"));

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(quickWidget);

    setLayout(layout);

    // quickWidget->rootContext()->setContextProperty("myCppObject", this);
}