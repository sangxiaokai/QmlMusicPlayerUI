#include "youtubemediaplayer.h"
#include "View/songview.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include<QDebug>

YoutubeMediaPlayer::YoutubeMediaPlayer(QObject *qmlItemPlayer):mQmlItemPlayer(qmlItemPlayer)
{

//    mView  = new QWebView();
//    mView->page()->networkAccessManager()->setCookieJar(new NetworkCookieJar);
//    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled,true );
//    connect(this, SIGNAL(playNewSong(QUrl)),this ,SLOT(loadNewSong(QUrl)));


//    mView->load(QUrl("https://connect.deezer.com/oauth/auth.php?app_id=144391&format=popup&redirect_uri=http://localhost:631&response_type=token&perms=email"));
//    mView->show();

    mCurrentTime.setSingleShot(true);
    connect(&mRefreshTime,SIGNAL(timeout()),this,SLOT(updatePlayingTime()));
    connect(&mCurrentTime,SIGNAL(timeout()),this,SLOT(songIsFinished()));
    mRefreshTime.setInterval(1000);
    mRefreshTime.start();
}



bool YoutubeMediaPlayer::play(QSharedPointer<SongView>s)
{
    qDebug()<<"Now Playing !! : "+ s->getName();

    QVariant returnedValue;
    QMetaObject::invokeMethod(mQmlItemPlayer, "play",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, s->getItemId()));
    mCurrentTime.stop();
    mCurrentTime.setInterval(1500 + s->getDuration()*1000);
    mCurrentTime.start();
    mRefreshTime.start();

    return true;


//    emit playNewSong(QUrl("qrc:/deezer/deezer.html?SongID=" + s->getItemId()));
}

void YoutubeMediaPlayer::pause()
{

    mCurrentTime.stop();
}

void YoutubeMediaPlayer::stop()
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(mQmlItemPlayer, "stop",
            Q_RETURN_ARG(QVariant, returnedValue));
    mCurrentTime.stop();

}

void YoutubeMediaPlayer::updatePlayingTime()
{
    emit CurrentTimeHasChanged();

}

int YoutubeMediaPlayer::getCurrentTime()
{
    return (mCurrentTime.interval() - mCurrentTime.remainingTime())/1000.f;
}

void YoutubeMediaPlayer::songIsFinished()
{
    mRefreshTime.stop();
    emit SongHasFinished();
}
