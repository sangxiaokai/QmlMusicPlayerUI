#ifndef ALBUMLISTMODEL_H
#define ALBUMLISTMODEL_H

#include <QAbstractListModel>
#include "View/albumview.h"

class AlbumListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AlbumListModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE
    void updateList();

protected:
    QList<AlbumView *> mAlbums;

signals:

public slots:

};

#endif // ALBUMLISTMODEL_H
