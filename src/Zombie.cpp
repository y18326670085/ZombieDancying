#include "Zombie.h"
#include <QMovie>
#include <QObject>

#define MAJORPATH ":/images/Zombies/"

Zombie::Zombie(QString zombieKind):zombieKind(zombieKind)
{
    pixMap = new QGraphicsPixmapItem();
    movie = new QMovie();
    pixMap->setPos(QPointF(900,100));

    connect(this->movie,&QMovie::frameChanged,[this](){
        this->pixMap->setPixmap(movie->currentPixmap());
    });
}

Zombie::~Zombie()
{
    delete movie;
    delete pixMap;
}

void Zombie::changeSrc(const QString newSrc)
{
    movie->setFileName(MAJORPATH + zombieKind + "/" + newSrc);
    movie->jumpToFrame(0);
    pixMap->setPixmap(movie->currentPixmap());
}

void Zombie::resetMovie()
{
    movie->jumpToFrame(0);
}

void Zombie::startMovie()
{
    movie->start();
}

void Zombie::stopMovie()
{
    movie->stop();
}
