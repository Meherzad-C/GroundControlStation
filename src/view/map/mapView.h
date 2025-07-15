#pragma once

#include <QWidget>
#include <QQuickWidget>
#include <QVBoxLayout>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDir>
#include <QQmlApplicationEngine>

class MapView : public QWidget {
    Q_OBJECT
public:
    explicit MapView(QWidget* parent = nullptr);
    QQmlApplicationEngine& engine() { return m_engine; }

private:
    QQuickWidget* m_quickWidget;
    QQmlApplicationEngine m_engine;
};
