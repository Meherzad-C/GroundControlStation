#pragma once
#include <QObject>
#include <QThread>
#include <QDebug>
#include "../../model/telemetry/telemetryModel.h"
#include "../../model/telemetry/telemetryPlayer.h"

class TelemetryController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool playing READ playing NOTIFY playingChanged)

public:
    explicit TelemetryController(QObject* parent = nullptr);
    ~TelemetryController() override;

    Q_INVOKABLE void loadTrack(const QString& filePath);
    Q_INVOKABLE void playPause();
    bool playing() const { return m_running; }

signals:
    void positionChanged(double lat, double lon, double yaw, int index);
    void playingChanged();

private:
    TelemetryModel   m_model;
    TelemetryPlayer* m_player  = nullptr;
    QThread*         m_thread  = nullptr;
    bool             m_running = false;
};
