#pragma once
#include <QObject>
#include <QTimer>
#include "telemetryModel.h"

class TelemetryPlayer : public QObject {
    Q_OBJECT
public:
    explicit TelemetryPlayer(QObject* parent = nullptr);

    void setModel(TelemetryModel* m) { m_model = m; }
    void setHz(int hz)               { m_interval = 1000 / hz; }

public slots:
    void start();
    void pause();

signals:
    void position(double lat, double lon, double yaw, int index);
    void finished(); // never fired (infinite loop) but good practice

private slots:
    void step();

private:
    TelemetryModel* m_model{ nullptr };
    QTimer* m_timer{ nullptr };
    int    m_idx{ 0 };
    int    m_interval{ 100 };    // 10 Hz
};
