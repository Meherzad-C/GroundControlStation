#pragma once
#include <QObject>
#include <QVector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

/*
Fields:
    t = elapsed seconds (double)
    lat, lon = WGS-84 
    alt = meters 
    yaw = degrees (0-360)
    gs = ground-speed (m/s)
    battery = %
*/
struct TelemetryData {
    double t, lat, lon, alt, yaw, gs, battery;
};

class TelemetryModel : public QObject {
    Q_OBJECT
public:
    explicit TelemetryModel(QObject* parent = nullptr);
    bool loadFromJson(const QString& filePath);
    const QVector<TelemetryData>& samples() const { return m_telemetryData; }

signals:
    void dataLoaded(int sampleCount);

private:
    QVector<TelemetryData> m_telemetryData;
};
