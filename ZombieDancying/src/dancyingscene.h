#ifndef DANCYINGSCENE_H
#define DANCYINGSCENE_H

#include <QGraphicsView>

class BackgroundItem;

class DancyingScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DancyingScene();
    ~DancyingScene();

    BackgroundItem *bgitem;
};

#endif // DANCYINGSCENE_H
