#include "dancyingscene.h"
#include "backgrounditem.h"
#include <QMovie>
#include "zombie.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QDir>
//#include <unistd.h>
#include "Timer.h"
#include "Animate.h"

DancyingScene::DancyingScene():bgitem(new BackgroundItem()), backplayer(new QMediaPlayer)
{
    addItem(bgitem);

//    QGraphicsPixmapItem *zombie = new QGraphicsPixmapItem();

//    QMovie *movie = new QMovie(":/images/Zombies/DancingZombie/Dancing.gif");
//    //QPixmap *zombieImg = new QPixmap(":/images/Zombies/DancingZombie/Dancing.gif");

//    movie->jumpToFrame(0);
//    zombie->setPixmap(movie->currentPixmap());
//    //zombie->setPixmap(*zombieImg);

//    zombie->setPos(QPointF(600,100));

//    //C++ lambda表达式
//    connect(movie,
//            &QMovie::frameChanged,
//            [zombie, movie](int i){ zombie->setPixmap(movie->currentPixmap()); }
//    );

//    movie->start();
//    addItem(zombie);

    for (int i = 0;i < 5;i++) {
        Zombie *dancyZomie = new Zombie("DancingZombie");
        dancyZomie->changeSrc("Dancing.gif");
        addItem(dancyZomie->pixMap);
        dancyZomie->startMovie();
        dancyZomie->pixMap->setPos(QPointF(900,i*100));

        zombies.push_back(dancyZomie);
    }

    //加载资源 播放...
//    QMediaPlayer *player = new QMediaPlayer();
//    //player->setMedia(QUrl("D:\QT Project\ZombieDancying\ZombieDancying\music\jljt.mp3"));
//    player->setMedia(QUrl::fromLocalFile("D:/QT Project/ZombieDancying/ZombieDancying/music/jljt.mp3"));
//    player->play();

    //sleep(3);
    //playBackMusic();

    (new Timer(this,
               3000,
               [this]{playBackMusic();}
                ))->start();

    (new Timer(this,
               2000,
               [this]{
                    zombies[2]->changeSrc("DancingZombie.gif");
                    //zombies[2]->pixMap->setPos(QPointF(400,200));
                    Animate(zombies[2]->pixMap).move(QPointF(400,200)).speed(0.1).finish();
                    Animate(zombies[2]->pixMap).scale(1.5).speed(0.1).finish();
                    Animate(zombies[2]->pixMap).fade(0.5).speed(0.1).finish();
                }
                ))->start();

//    (new Timer(this,
//               3000,
//               [this]{playBackMusic();
//                        (new Timer(this,
//                                   2000,
//                                   [this]{zombies[2]->changeSrc("DancingZombie.gif");}
//                                    ))->start();}
//                ))->start();

}

DancyingScene::~DancyingScene()
{
    delete bgitem;
    delete backplayer;
}

void DancyingScene::playBackMusic()
{
    //加载资源 播放...
    QMediaPlayer *player = new QMediaPlayer();
    //player->setMedia(QUrl("D:\QT Project\ZombieDancying\ZombieDancying\music\jljt.mp3"));
    player->setMedia(QUrl::fromLocalFile("D:/QT Project/ZombieDancying/ZombieDancying/music/jljt.mp3"));

    qDebug() << qApp->applicationFilePath();
    qDebug() << qApp->applicationDirPath();
    qDebug() << QDir::currentPath();

    //文件夹处理
    QString fullPath = qApp->applicationDirPath();
    QStringList pathList = fullPath.split('/');
    for(int i=0; i< pathList.length(); i++)
    {
        qDebug() << pathList[i];
    }

    player->play();
}
