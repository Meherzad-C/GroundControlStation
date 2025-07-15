#include "telemetryPlayer.h"

TelemetryPlayer::TelemetryPlayer(QObject* parent) : QObject(parent) {}

void TelemetryPlayer::start() {
	if (!m_timer) {
		m_timer = new QTimer();
		m_timer->setInterval(100);  // 10 Hz
		connect(m_timer, &QTimer::timeout, this, &TelemetryPlayer::step);
		m_timer->moveToThread(this->thread());  // run in worker thread
	}
	if (!m_timer->isActive()) {
		m_timer->start();
	}
}

void TelemetryPlayer::pause() {
	if (m_timer && m_timer->isActive()) {
		m_timer->stop();
	}
}

void TelemetryPlayer::step() {
	if (!m_model) return;
	const auto& s = m_model->samples();
	if (s.isEmpty()) return;

	const auto& p = s[m_idx];
	emit position(p.lat, p.lon, p.yaw, m_idx);
	m_idx = (m_idx + 1) % s.size(); // loop forever
}
