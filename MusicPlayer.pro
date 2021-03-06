TEMPLATE = app

QT += qml quick widgets xml svg multimedia webchannel websockets


QTPLUGIN += qsvg
SOURCES += main.cpp \
    FakeMusicCollection/Model/album.cpp \
    FakeMusicCollection/Model/artist.cpp \
    FakeMusicCollection/Model/collection.cpp \
    FakeMusicCollection/Model/song.cpp \
    Dao/daocollection.cpp \
    Player/player.cpp \
    Player/playlistmodel.cpp \
    Service/jacketprovider.cpp \
    Service/collectionmanager.cpp \
    Dao/daodeezercollection.cpp \
    Player/abstractmediaplayer.cpp \
    Player/audiostreammediaplayer.cpp \
    Player/DeezerPlayer/deezermediaplayer.cpp \
    Player/DeezerPlayer/networkcookiejar.cpp \
    Player/DeezerPlayer/websocketclientwrapper.cpp \
    Player/DeezerPlayer/websockettransport.cpp \
    View/albumview.cpp \
    View/artistview.cpp \
    View/collectionview.cpp \
    View/songview.cpp \
    Player/searchtrackmodel.cpp \
    Player/albumlistmodel.cpp \
    Service/servicecollectiondeezer.cpp \
    Service/servicecollectionxml.cpp \
    Player/playlistlistmodel.cpp \
    Dao/networkworker.cpp \
    Dao/daoyoutubecollection.cpp \
    Service/servicecollectionyoutube.cpp \
    Player/YoutubePlayer/youtubemediaplayer.cpp

RESOURCES += QML/qml.qrc \
    Icons/Graphics.qrc \
    FakeMusicCollection/FakeMusicCollection.qrc \
    Player/DeezerPlayer/DeezerRessources.qrc \
    Player/YoutubePlayer/YoutubeRessources.qrc

CONFIG+=qml_debug

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    FakeMusicCollection/Model/album.h \
    FakeMusicCollection/Model/artist.h \
    FakeMusicCollection/Model/collection.h \
    FakeMusicCollection/Model/song.h \
    FakeMusicCollection/Model/abstractcollectionitem.h \
    Player/player.h \
    Player/playlistmodel.h \
    Service/jacketprovider.h \
    Service/collectionmanager.h \
    Dao/daodeezercollection.h \
    Dao/daocollection.h \
    Player/abstractmediaplayer.h \
    Player/audiostreammediaplayer.h \
    Player/DeezerPlayer/deezermediaplayer.h \
    Player/DeezerPlayer/networkcookiejar.h \
    Player/DeezerPlayer/websocketclientwrapper.h \
    Player/DeezerPlayer/websockettransport.h \
    View/abstractcollectionitemview.h \
    View/albumview.h \
    View/artistview.h \
    View/collectionview.h \
    View/songview.h \
    Player/searchtrackmodel.h \
    Player/albumlistmodel.h \
    Service/abstractservicecollection.h \
    Service/servicecollectiondeezer.h \
    Service/servicecollectionxml.h \
    Player/playlistlistmodel.h \
    Dao/networkworker.h \
    Dao/daoyoutubecollection.h \
    Service/servicecollectionyoutube.h \
    Player/YoutubePlayer/youtubemediaplayer.h

copydata.commands = $(COPY_DIR) $$system_path($$PWD/Player/DeezerPlayer) $$system_path($$OUT_PWD)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

OTHER_FILES += \
    Readme.txt
