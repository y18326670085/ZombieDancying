#ifndef DANCYINGSCENE_H
#define DANCYINGSCENE_H

#include <QGraphicsView>

class Zombie;
class BackgroundItem;


class DancyingScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DancyingScene();
    ~DancyingScene();

    QList<Zombie *> zombies;

    BackgroundItem *bgitem;
};

#endif // DANCYINGSCENE_H
