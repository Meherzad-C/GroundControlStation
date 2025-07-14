#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QWidget>
#include <QQuickWidget>
#include <QVBoxLayout>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDir>

class MapView : public QWidget
{
    Q_OBJECT
public:
    explicit MapView(QWidget* parent = nullptr);


private:
    QQuickWidget* quickWidget;
};

#endif // MAPVIEW_H
