#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QSlider>
#include <QDir>
#include <QStringList>
#include <QListView>
#include <QLabel>
#include "playlist.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class
 * To play media
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMediaPlayer::State state() const;

private slots:

    void on_actionOpen_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionPlay_triggered();

    void on_vSlider_sliderMoved(int position);

    void durationChanged (qint64 position);

    void positionChanged (qint64 position);

    void on_dial_sliderMoved(int position);

    void on_actionNext_triggered();

    void on_actionPrevious_triggered();

    void on_playbutton_clicked();

    void on_stopbutton_clicked();

    void on_nextbutton_clicked();

    void on_prebutton_clicked();

    void on_shuffle_clicked();

    void on_mute_clicked();

    void aboutUs();

    void on_actionShuffle_triggered();

    void on_actionMute_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QSlider *slider;
    QListView *playlistView;
    QLabel *label;
    QStringList *list;
    QMediaPlayer::State playerState;
    QLabel *time;

    //playlist *p;
};

#endif // MAINWINDOW_H
