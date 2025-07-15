#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QVideoWidget>

class VideoFileModel : public QObject {
    Q_OBJECT

public:
    explicit VideoFileModel(QObject* parent = nullptr);

    QMediaPlayer* getMediaPlayer();
    QVideoWidget* getVideoWidget();

    void setSource(const QString& filePath);
    void play();
    void stop();

private slots:
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    QMediaPlayer* m_mediaPlayer;
    QVideoWidget* m_videoWidget;
};