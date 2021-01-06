#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QMainWindow>
#include <QMediaPlayer>

class playlist : public QMainWindow
{
    Q_OBJECT
public:
    explicit playlist(QWidget *parent = 0);

signals:

public slots:
    void openAction();

private:
    QMediaPlayer *player;
    QMediaPlaylist *playlistVar;
};

#endif // PLAYLIST_H
