#include "HelloWorldScene.h"
#include "GameSharing.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    auto clickMe = MenuItemLabel::create(LabelTTF::create("Click Me!", "Arial", 51),
                                        [](Object *obj) {
                                            GameSharing::SubmitScore(rand());
                                            GameSharing::ShowLeaderboards();
                                        });
    
	clickMe->setPosition(Vec2(origin.x + visibleSize.width /2  ,
                                origin.y + visibleSize.height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(clickMe, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    GameSharing::initGameSharing();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
