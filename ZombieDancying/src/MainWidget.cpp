#include "MainWidget.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "dancyingview.h"
#include <QLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), dancyView(new DancyingView(this))
{
//    QGraphicsView *newView = new QGraphicsView(this);
//    //newView->setStyle("background-color:red");

//    //设置newView的位置
//    newView->setGeometry(0,0,900,600);

//    QGraphicsScene *newScene = new QGraphicsScene();
//    newView->setScene(newScene);

//    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
//    QPixmap *backImg = new QPixmap(":/images/background1.jpg");
//    background->setPixmap(*backImg);

//    newScene->addItem(background);

//    04 布局和动图播放
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(dancyView);
    setLayout(layout);
    layout->setMargin(0);

}

MainWidget::~MainWidget()
{
}

