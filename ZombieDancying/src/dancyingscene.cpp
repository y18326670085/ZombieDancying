#include "dancyingscene.h"
#include "backgrounditem.h"
#include <QMovie>
#include "zombie.h"
#include <QMediaPlayer>

DancyingScene::DancyingScene():bgitem(new BackgroundItem())
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
}

DancyingScene::~DancyingScene()
{
    delete bgitem;
}
