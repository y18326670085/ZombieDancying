#include "backgrounditem.h"

BackgroundItem::BackgroundItem():backImg(new QPixmap(":/images/background1.jpg"))
{
    this->setPixmap(*backImg);
}

BackgroundItem::~BackgroundItem()
{
    delete backImg;
}
