#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QWidget>
#include <QGraphicsPixmapItem>

#include <QObject>

class Zombie : QObject
{
    Q_OBJECT
public:
    Zombie(QString zombieKind);
    ~Zombie();
    QGraphicsPixmapItem *pixMap;
    QString zombieKind;
    QString gifSrc;
    QMovie *movie;

    void changeSrc(const QString newSrc);
    void resetMovie();
    void startMovie();
    void stopMovie();
};

#endif // ZOMBIE_H
