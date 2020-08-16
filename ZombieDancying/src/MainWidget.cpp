#include "MainWidget.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QGraphicsView *newView = new QGraphicsView(this);
    //newView->setStyle("background-color:red");

    //设置newView的位置
    newView->setGeometry(100,100,300,200);

    QGraphicsScene *newScene = new QGraphicsScene();
    newView->setScene(newScene);

    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    newScene->addItem(background);
}

MainWidget::~MainWidget()
{
}

