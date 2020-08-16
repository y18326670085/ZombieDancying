#ifndef DANCYINGVIEW_H
#define DANCYINGVIEW_H

#include <QGraphicsView>

class DancyingView : public QGraphicsView
{
    Q_OBJECT

public:
    DancyingView(QWidget *parent = nullptr);
    ~DancyingView();

    qreal width, height;
};

#endif // DANCYINGVIEW_H
