#include "MainWidget.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QGraphicsView *newView = new QGraphicsView(this);
    //newView->setStyle("background-color:red");

    //设置newView的位置
    newView->setGeometry(0,0,900,600);

    QGraphicsScene *newScene = new QGraphicsScene();
    newView->setScene(newScene);

    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    QPixmap *backImg = new QPixmap(":/images/background1.jpg");
    background->setPixmap(*backImg);

    newScene->addItem(background);
}

MainWidget::~MainWidget()
{
}

