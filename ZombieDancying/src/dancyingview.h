#ifndef DANCYINGVIEW_H
#define DANCYINGVIEW_H

#include <QGraphicsView>

class DancyingScene;
class DancyingView : public QGraphicsView
{
    Q_OBJECT

public:
    DancyingView(QWidget *parent = nullptr);
    ~DancyingView();

    qreal width, height;
    DancyingScene *dancyingScene;

    void resizeEvent(QResizeEvent *event) override;
};

#endif // DANCYINGVIEW_H
