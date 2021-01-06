#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controls.h"
#include "playlist.h"
#include <QMessageBox>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    player->setPlaylist(playlist);



    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);


    connect(ui->actionActionAboutUs,SIGNAL(triggered(bool)),this,SLOT(aboutUs()));
    connect(ui->actionAboutQt,SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));


    //connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(on_actionOpen_triggered()));


    // setup Gui
    QPixmap pix1(":/icon/icon/play.png");
    QPixmap pix2(":/icon/icon/stop.png");
    QPixmap pix3(":/icon/icon/pre.png");
    QPixmap pix4(":/icon/icon/next.png");
    QPixmap pix5(":/icon/icon/search.png");
    QPixmap pix6(":/icon/icon/unshuffle.png");
    QPixmap pix7(":/icon/icon/mute.png");
    QPixmap pix8(":/icon/icon/equalizer.gif");
    QString style= "QPushButton{border: none;outline: none;}";


    ui->playbutton->setIcon(QIcon(pix1)); ui->playbutton->setStyleSheet(style); ui->playbutton->setToolTip("Play");
    ui->stopbutton->setIcon(QIcon(pix2)); ui->stopbutton->setStyleSheet(style); ui->stopbutton->setToolTip("Stop");
    ui->nextbutton->setIcon(QIcon(pix3)); ui->nextbutton->setStyleSheet(style); ui->nextbutton->setToolTip("Next Song");
    ui->prebutton->setIcon(QIcon(pix4));  ui->prebutton->setStyleSheet(style);  ui->prebutton->setToolTip("Previous Song");
    ui->shuffle->setIcon(QIcon(pix6));    ui->shuffle->setStyleSheet(style);    ui->shuffle->setToolTip("Shuffle songs");
    ui->mute->setIcon(QIcon(pix7));       ui->mute->setStyleSheet(style);       ui->mute->setToolTip("Mute Song"); ui->mute->setText(".");
    ui->art->setPixmap(pix8);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

        // Action Open file
        QStringList fileName;
        fileName.clear();
        fileName = QFileDialog::getOpenFileNames(this,"Open mp3 Files","","mp3 File(*.mp3 *MP3)");
        on_actionStop_triggered();

        if(!fileName.empty()){
                playlist->clear();
                ui->listWidget->clear();

                /*Attempt to insert file name to QListWidget*/
//                QFileInfo fi(fileName);
//                QString base = fi.baseName();
//                QStringList list = fileName;
//                QStringList::Iterator it = list.begin();
//                while( it != list.end() ) {
//                ui->listWidget->insertItem( ui->listWidget, *it);
//                ++it;}

        ui->listWidget->addItems(fileName);
        QPixmap pix1(":/icon/icon/pause.png");
        ui->playbutton->setIcon(pix1);


        foreach (QString const &argument, fileName) {
               QFileInfo fileInfo(argument);
               if (fileInfo.exists()) {

                   /*Change Album Art*/

                   switch (player->state()) {
                   case QMediaPlayer::PlayingState:
                   {QMovie *movie = new QMovie(":/icon/icon/equalizer.gif");
                       QLabel *processLabel = new QLabel(this);
                       processLabel->setMovie(movie);
                       movie->start();}
                       break;

                   default:
                       QPixmap pix8(":/icon/icon/equalizer.gif");
                       ui->art->setPixmap(pix8);
                       break;
                   }
                  // QString albumart = player->metaData("CoverArtImage").type();
                   //ui->art->setPixmap(albumart);

                   /*Load media files to QPlaylist*/

                    QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
                   if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
                       playlist->load(url);
                   } else
                       playlist->addMedia(url);
               } else {
                   QUrl url(argument);
                   if (url.isValid()) {
                       playlist->addMedia(url);
                   }
               }
           }
        player->setPlaylist(playlist);
        on_actionPlay_triggered();


        //slider->setValue(position);
//        QString time = QTime duration(0, position / 60000, qRound((position % 60000) / 1000.0));
//        ui->time->setText(time);

}}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
}

void MainWindow::on_vSlider_sliderMoved(int position)
{
    player->setPosition(position);
//    QString time = QTime duration(0, position / 60000, qRound((position % 60000) / 1000.0));
//    ui->time->setText(time);
}

void MainWindow::durationChanged(qint64 position)
{
    ui->vSlider->setMaximum(position);
}

void MainWindow::positionChanged(qint64 position)
{
    ui->vSlider->setValue(position);
}

void MainWindow::on_dial_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_actionNext_triggered()
{
    playlist->next();
}

void MainWindow::on_actionPrevious_triggered()
{
    playlist->previous();
}

void MainWindow::on_playbutton_clicked()
{
//    if (player->state() == QMediaPlayer::PlayingState) {
//        player->pause();
//        ui->playbutton->setToolTip(tr("Play"));
//        QPixmap pix(":/icon/icon/play.png");
//        ui->playbutton->setIcon(QIcon(pix));
//        ui->playbutton->setStyleSheet("QPushButton{border: none;outline: none;}");
//        ui->status->setText("Paused...");


//    } else  {
//        player->play();
//        ui->playbutton->setToolTip(tr("Pause"));
//        QPixmap pix1(":/icon/icon/pause.png");
//        ui->playbutton->setIcon(QIcon(pix1));
//        ui->playbutton->setStyleSheet("QPushButton{border: none;outline: none;}");
//        ui->status->setText("Playing...");

//    }


 switch (player->state()) {
 case QMediaPlayer::PlayingState:{
     player->pause();
     ui->playbutton->setToolTip(tr("Play"));
     QPixmap icon(":/icon/icon/play.png");
     ui->playbutton->setIcon(QIcon(icon));
     ui->playbutton->setStyleSheet("QPushButton{border: none;outline: none;}");
     ui->status->setText("Paused...");
     }
     break;

 case QMediaPlayer::PausedState:{
     player->play();
     ui->playbutton->setToolTip(tr("Pause"));
     QPixmap pix1(":/icon/icon/pause.png");
     ui->playbutton->setIcon(QIcon(pix1));
     ui->playbutton->setStyleSheet("QPushButton{border: none;outline: none;}");
     ui->status->setText("Playing...");}
     break;

 default:{
     player->play();
     ui->playbutton->setToolTip(tr("Play"));
     QPixmap pixd(":/icon/icon/play.png");
     ui->playbutton->setIcon(QIcon(pixd));
     QString title = player->metaData("Title").toString();
     if (!title.isEmpty())
         ui->infoLabel->setText(title);}
     break;
 }


}



void MainWindow::on_stopbutton_clicked()
{
    player->stop();
     QPixmap pix1(":/icon/icon/play.png");
    ui->playbutton->setIcon(QIcon(pix1));
    ui->status->setText("Stoped...");
}



void MainWindow::on_nextbutton_clicked()
{
    playlist->next();
    ui->status->setText("Previous Song...");
    ui->infoLabel->setText(player->metaData("Title").toString());
    QString title = player->metaData("Title").toString();
    if (!title.isEmpty())
        ui->infoLabel->setText(title);
}

void MainWindow::on_prebutton_clicked()
{
    playlist->next();
    ui->status->setText("Next Song...");
    QString title = player->metaData("Title").toString();
    if (!title.isEmpty())
        ui->infoLabel->setText(title);
}

void MainWindow::on_shuffle_clicked()
{
    if(player->state()== QMediaPlayer::PlayingState){
        playlist->shuffle();
        ui->status->setText("Shuffle On...");
    }
    else{
        ui->status->setText("Shuffle off...");
    }
}

void MainWindow::on_mute_clicked()
{
    if(ui->mute->text() == "."){
        player->setMuted(true);
        QPixmap pix7(":/icon/icon/unmute.png");
        ui->mute->setIcon(QIcon(pix7));
        ui->mute->setText(" ");
        ui->status->setText("Muted...");

    }
    else{
        player->setMuted(false);
        ui->mute->setText(".");
        QPixmap pix8(":/icon/icon/mute.png");
        ui->mute->setIcon(QIcon(pix8));
        ui->status->setText("Unmuted...");
    }

}

void MainWindow::aboutUs()
{
    QMessageBox::about(this,tr("About MP3Factory"),
                       QString("<u><b>MP3 Factory</b></u> by Akila Geethanjana <br>"

                               ""
                               ""));
}


void MainWindow::on_actionShuffle_triggered()
{
    if(player->state()== QMediaPlayer::PlayingState){
        playlist->shuffle();
        ui->status->setText("Shuffle On...");
    }
    else{
        ui->status->setText("Shuffle off...");
    }
}

void MainWindow::on_actionMute_triggered()
{
    if(ui->mute->text() == "."){
        player->setMuted(true);
        QPixmap pix7(":/icon/icon/unmute.png");
        ui->mute->setIcon(QIcon(pix7));
        ui->mute->setText(" ");
        ui->status->setText("Muted...");

    }
    else{
        player->setMuted(false);
        ui->mute->setText(".");
        QPixmap pix8(":/icon/icon/mute.png");
        ui->mute->setIcon(QIcon(pix8));
        ui->status->setText("Unmuted...");
    }
}
