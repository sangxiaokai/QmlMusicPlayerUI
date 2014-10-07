#include "player.h"
#include <QDebug>
#include "Dao/daocollection.h"
#include "Service/servicecollection.h"
#include "Service/collectionmanager.h"
#include "Player/audiostreammediaplayer.h"
#include "Player/DeezerPlayer/deezermediaplayer.h"
#include "Model/song.h"
#include <QApplication>
#include <QQmlApplicationEngine>

Player::Player(QObject *parent) :
    QObject(parent)
{


    mPlaylistModel = new PlaylistModel;
    mPlaylistModel->addSongs(CollectionManager::getInstance()->getServiceCollection("DeezerDatabase")->getAllSongs());
    mPlaylistModel->addSongs(CollectionManager::getInstance()->getServiceCollection("FakeDatabase")->getAllSongs());
    mAbstractMediaPlayer = NULL;



}

PlaylistModel * Player::getPlaylistModel()
{
    return mPlaylistModel;
}


Song * Player::getNowPlayingSong()
{
    return mPlaylistModel->getNowPlayingSong();
}

bool Player::play(int index)
{
    mPlaylistModel->setNowPlayingSong(index);
    Song *s  = mPlaylistModel->getNowPlayingSong();

    if (mAbstractMediaPlayer != CollectionManager::getInstance()->getMediaPlayerCollection(s->getCollectionId()))
    {
        if (mAbstractMediaPlayer)
        {
            mAbstractMediaPlayer->stop();
            disconnect(mAbstractMediaPlayer);
        }
        mAbstractMediaPlayer = CollectionManager::getInstance()->getMediaPlayerCollection(s->getCollectionId());
        connect(mAbstractMediaPlayer,SIGNAL(SongHasFinished()),this,SLOT(playNextSong()));
            connect(mAbstractMediaPlayer,SIGNAL(CurrentTimeHasChanged(int)),this,SLOT(setCurrentTime(int)));
    }


    setCurrentTime(0);

    mAbstractMediaPlayer->play(s);
    emit nowPlayingSongHasChanged();
}

void Player::pause()
{
    mAbstractMediaPlayer->pause();
}

int Player::getCurrentTime()
{
    int retour = 0;
    if (mAbstractMediaPlayer)
        retour = mAbstractMediaPlayer->getCurrentTime();
    return retour;
}

void Player::setCurrentTime(int seconds)
{
    emit CurrentTimeHasChanged();
}

bool Player::playNextSong()
{
    qDebug()<<"next song !";
    mPlaylistModel->goToNextTrack();
    play(mPlaylistModel->getNowPlayingSongIndex());
}
