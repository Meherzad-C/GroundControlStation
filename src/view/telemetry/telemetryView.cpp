#include "telemetryView.h"

TelemetryView::TelemetryView(QWidget* parent)
	: QWidget(parent) {
	auto* layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);

	m_mapWidget = new QQuickWidget(this);
	m_mapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

	m_engine.rootContext()->setContextProperty("telemetryCtrl", &m_telemetryController);

	connect(m_mapWidget, &QQuickWidget::statusChanged, this, [this](QQuickWidget::Status status) {
		if (status != QQuickWidget::Ready)
			return;

		QObject* receiver = m_mapWidget->rootObject()->findChild<QObject*>("signalReceiver");

		if (!receiver) {
			qWarning() << "signalReceiver not found!";
			return;
		}

		connect(&m_telemetryController, &TelemetryController::positionChanged,
			receiver, [receiver](double lat, double lon, double yaw, int idx) {
				bool ok = QMetaObject::invokeMethod(receiver, "handlePosition",
				Q_ARG(QVariant, lat),
				Q_ARG(QVariant, lon),
				Q_ARG(QVariant, yaw),
				Q_ARG(QVariant, idx));
		if (!ok)
			qWarning() << "invokeMethod failed!";
			});
		});

	m_mapWidget->setSource(QUrl(QStringLiteral("qrc:/qml/maps/mapView.qml")));

	layout->addWidget(m_mapWidget);
	setLayout(layout);

	const QString jsonPath = ":/telemetry_data/drone_track.json";
	if (QFileInfo::exists(jsonPath)) {
		m_telemetryController.loadTrack(jsonPath);
	}
	else {
		qDebug() << "telemetry file not found";
	}
}
