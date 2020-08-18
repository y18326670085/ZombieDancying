#include "dancyingview.h"
#include "dancyingscene.h"

DancyingView::DancyingView(QWidget *parent):QGraphicsView(parent),
    width(900),height(600),
    dancyingScene(new DancyingScene())
{
    //设置窗口最小值
    setMinimumSize(width, height);

    //不显示滚动条
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setScene(dancyingScene);
}

DancyingView::~DancyingView()
{

}

void DancyingView::resizeEvent(QResizeEvent *event)
{
    QRect viewRect = frameRect();
    QTransform trans;
    trans.scale(viewRect.width()/width, viewRect.height()/height);
    setTransform(trans);
}




