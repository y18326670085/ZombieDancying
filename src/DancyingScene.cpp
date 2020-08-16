#include "DancyingScene.h"
#include "BackgroundItem.h"
#include <QMovie>
#include "Zombie.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QDir>

#include "Timer.h"
#include "Animate.h"

DancyingScene::DancyingScene():bgItem(new BackgroundItem()),backPlayer(new QMediaPlayer)
{
    addItem(bgItem);

    for (int i = 0;i < 5;i++) {
        Zombie *dancyZomie = new Zombie("DancingZombie");
        dancyZomie->changeSrc("Dancing.gif");
        addItem(dancyZomie->pixMap);
        dancyZomie->startMovie();
        dancyZomie->pixMap->setPos(QPointF(900,i*100));

        zombies.push_back(dancyZomie);
    }

    (new Timer(this,3000,[this]{
        playBackMusic();
    }))->start();

    (new Timer(this,2000,[this]{
        zombies[2]->changeSrc("DancingZombie.gif");
        //zombies[2]->pixMap->setPos(QPointF(400,200));

        Animate(zombies[2]->pixMap).move(QPointF(400,200)).speed(0.1).finish();
        Animate(zombies[2]->pixMap).scale(1.5).speed(0.1).finish();
        Animate(zombies[2]->pixMap).fade(0.5).speed(0.1).finish();
    }))->start();
}

DancyingScene::~DancyingScene()
{
    delete bgItem;
    delete backPlayer;
}

void DancyingScene::playBackMusic()
{
    // 加载资源 播放 ……
    //QMediaPlayer *player = new QMediaPlayer();
    //player->setMedia(QUrl::fromLocalFile("/Users/wy/Desktop/ZombieDancying/music/jljt.mp3"));
    qDebug() << qApp->applicationFilePath();
    qDebug() << qApp->applicationDirPath();
    qDebug() << QDir::currentPath();

    // 文件夹处理
    QString fullPath = qApp->applicationDirPath();
    QStringList pathList = fullPath.split('/');
    int currentIndex = 0;
    for (int i = 0;i < pathList.size();i++) {
        //qDebug() << pathList[i];
        if(pathList[i] == qAppName() + ".app")
        {
            currentIndex = i;
            break;
        }
    }
    qDebug() << currentIndex;
    QString musicDirPath = "";
    for (int i = 0;i < currentIndex - 1;i++) {
        musicDirPath = musicDirPath + pathList[i] + "/";
    }
    qDebug() << musicDirPath;
    musicDirPath += "music/";

    backPlayer->setMedia(QUrl::fromLocalFile(musicDirPath + "jljt.mp3"));
    backPlayer->play();

//    QDir dir(qApp->applicationDirPath());
//    dir.cdUp();
//    dir.cd("music");

//    if(!dir.exists())
//    {
//        // 下载
//    }
}
