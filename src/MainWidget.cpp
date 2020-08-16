#include "MainWidget.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "DancyingView.h"
#include <QLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),dancyView(new DancyingView(this))
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(dancyView);
    setLayout(layout);

    layout->setMargin(0);

}

MainWidget::~MainWidget()
{
}

