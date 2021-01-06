//#include "controls.h"
//#include "mainwindow.h"
//#include "ui_mainwindow.h"
//#include <QToolButton>

//controls::controls(QWidget *parent) : QMainWindow(parent),playerState(QMediaPlayer::StoppedState)
//{
//    QPixmap pix1(":/icon/icon/play.png");
//    QPixmap pix2(":/icon/icon/stop.png");
//    QPixmap pix3(":/icon/icon/pre.png");
//    QPixmap pix4(":/icon/icon/next.png");
//    QPixmap pix5(":/icon/icon/search.png");
//    QPixmap pix6(":/icon/icon/unshuffle.png");
//    QPixmap pix7(":/icon/icon/mute.png");
//    QString style= "QPushButton{border: none;outline: none;}";

//    playbutton = new QToolButton(this);
//    playbutton->setIcon(QIcon(pix1)); playbutton->setStyleSheet(style); playbutton->setToolTip("Play");
//    stopbutton->setIcon(QIcon(pix2)); stopbutton->setStyleSheet(style); stopbutton->setToolTip("Stop");
//    nextbutton->setIcon(QIcon(pix3)); nextbutton->setStyleSheet(style); nextbutton->setToolTip("Next Song");
//    prebutton->setIcon(QIcon(pix4));  prebutton->setStyleSheet(style);  prebutton->setToolTip("Previous Song");
//    search->setIcon(QIcon(pix5));     search->setStyleSheet(style);     search->setToolTip("Open file to Play");
//    shuffle->setIcon(QIcon(pix6));    shuffle->setStyleSheet(style);    shuffle->setToolTip("Shuffle songs");
//    mute->setIcon(QIcon(pix7));       mute->setStyleSheet(style);       mute->setToolTip("Mute Song"); mute->setText(".");


//    connect(playbutton, SIGNAL(clicked()), this, SLOT(playClicked()));
//    connect(stopbutton, SIGNAL(clicked()), this, SLOT(stop()));
//    connect(nextbutton, SIGNAL(clicked()), this, SLOT(next()));
//    connect(prebutton, SIGNAL(clicked()), this, SLOT(previous()));
//    connect(search, SIGNAL(clicked()), this, SLOT(playClicked()));
//    connect(shuffle, SIGNAL(clicked()), this, SLOT(playClicked()));
//    mute(search, SIGNAL(clicked()), this, SLOT(muteClicked()));

//}


//QMediaPlayer::State controls::state() const
//{
//    return playerState;
//}

//void controls::setState(QMediaPlayer::State state)
//{
//    if (state != playerState) {
//        playerState = state;

//        switch (state) {
//        case QMediaPlayer::StoppedState:
//            stopButton->setEnabled(false);
//            playButton->setIcon(QIcon(pix1);
//            break;
//        case QMediaPlayer::PlayingState:
//            stopButton->setEnabled(true);
//            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
//            break;
//        case QMediaPlayer::PausedState:
//            stopButton->setEnabled(true);
//            playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
//            break;
//        }
//    }
//}
//void controls::muteClicked()
//{
//    emit changeMuting(!playerMuted);
//}
