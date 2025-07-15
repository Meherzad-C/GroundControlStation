#include "telemetryModel.h"

TelemetryModel::TelemetryModel(QObject* parent) : QObject(parent) {}

bool TelemetryModel::loadFromJson(const QString& filePath) {
    QFile f(filePath);
    if (!f.open(QIODevice::ReadOnly)) return false;

    QJsonArray arr = QJsonDocument::fromJson(f.readAll()).array();
    m_telemetryData.reserve(arr.size());
    m_telemetryData.clear();

    for (auto v : arr) {
        auto o = v.toObject();
        m_telemetryData.append({
            o["t"].toDouble(),
            o["lat"].toDouble(),
            o["lon"].toDouble(),
            o["alt"].toDouble(),
            o["yaw"].toDouble(),
            o["gs"].toDouble(),
            o["battery"].toDouble()
        });
    }
    emit dataLoaded(m_telemetryData.size());
    return true;
}
