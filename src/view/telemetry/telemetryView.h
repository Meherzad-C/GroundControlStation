#pragma once
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWidget>
#include <QQuickWidget>
#include <QBoxLayout>
#include <QFileInfo>
#include <QMetaObject>
#include <QQuickItem>
#include "../../controller/telemetry/telemetryController.h"

class TelemetryView : public QWidget {
    Q_OBJECT
public:
    explicit TelemetryView(QWidget* parent = nullptr);

private:
    QQuickWidget* m_mapWidget{ nullptr };
    QQmlApplicationEngine m_engine;
    TelemetryController   m_telemetryController;
};
