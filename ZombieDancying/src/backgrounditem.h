#ifndef BACKGROUNDITEM_H
#define BACKGROUNDITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class BackgroundItem :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BackgroundItem();
    ~BackgroundItem();

    QPixmap *backImg;
};

#endif // BACKGROUNDITEM_H
