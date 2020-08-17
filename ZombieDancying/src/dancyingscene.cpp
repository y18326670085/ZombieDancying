#include "dancyingscene.h"
#include "backgrounditem.h"

DancyingScene::DancyingScene():bgitem(new BackgroundItem())
{
    addItem(bgitem);
}

DancyingScene::~DancyingScene()
{
    delete bgitem;
}
