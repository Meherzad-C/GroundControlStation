#include "telemetryController.h"

TelemetryController::TelemetryController(QObject* parent) : QObject(parent) {}

TelemetryController::~TelemetryController() {
    if (m_thread) {
        m_player->pause();
        m_thread->quit();
        m_thread->wait();
    }
}

void TelemetryController::loadTrack(const QString& path) {
    if (!m_model.loadFromJson(path)) {
        qDebug() << "TelemetryController::loadTrack() load from json failed";
        return;
    }

    // dispose previous thread if any
    if (m_thread) {
        m_player->pause();
        m_thread->quit();
        m_thread->wait();
        m_thread->deleteLater();
    }

    m_thread  = new QThread(this);
    m_player  = new TelemetryPlayer;
    m_player->setModel(&m_model);
    m_player->moveToThread(m_thread);

    connect(m_thread,  &QThread::started,  m_player, &TelemetryPlayer::start);
    connect(m_player,  &TelemetryPlayer::position,
            this,      &TelemetryController::positionChanged,
            Qt::QueuedConnection);

    m_thread->start();
    m_running = true;
    emit playingChanged();
}

void TelemetryController::playPause() {
    if (!m_player) return;

    if (m_running) {
        m_player->pause();
        m_running = false;
    } else {
        QMetaObject::invokeMethod(m_player, "start", Qt::QueuedConnection);
        m_running = true;
    }
    emit playingChanged();
}
