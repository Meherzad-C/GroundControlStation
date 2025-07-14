#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QVideoWidget>

class FileVideoModel : public QObject {
    Q_OBJECT

public:
    explicit FileVideoModel(QObject* parent = nullptr);

    QMediaPlayer* getMediaPlayer();
    QVideoWidget* getVideoWidget();

    void setSource(const QString& filePath);
    void play();
    void stop();

private slots:
    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
};
