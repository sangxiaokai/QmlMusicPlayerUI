#include "album.h"


Album::Album(int id,QString idCollection,QString Name, Artist * m ,QUrl jacket, QObject *parent) :AbstractCollectionItem(id,idCollection,parent),mArtist(m),mName(Name),mJacket(jacket)
{
}

Album::Album(QObject *parent)
{
    mName = "undefined";


}

const QList<Song*>& Album::getSongs() const
{
    return mSongs;
}



void Album::addSong(Song *s)
{
    mSongs.append(s);
}

const QString & Album::getName() const
{
    return mName;
}

Artist *Album::getArtist() const
{

    return mArtist;
}

QUrl Album::getJacket() const
{
    return mJacket;
}
