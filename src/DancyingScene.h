#ifndef DANCYINGSCENE_H
#define DANCYINGSCENE_H

#include <QGraphicsScene>
class Zombie;
class BackgroundItem;
class QMediaPlayer;
class DancyingScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DancyingScene();
    ~DancyingScene();

    QList<Zombie *> zombies;

    BackgroundItem *bgItem;
    QMediaPlayer *backPlayer;

    void playBackMusic();
};

#endif // DANCYINGSCENE_H
