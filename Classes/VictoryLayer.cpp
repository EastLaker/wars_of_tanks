#include "VictoryLayer.h"
#include "GameScene.h"
#include "HelloWorldScene.h"
#include "ChoseLevel.h"

bool VictoryLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Sprite * bgPause = Sprite::create("UI/gameover/result_bg.png");
	bgPause->setAnchorPoint(Vec2(0.5, 0.5));
	
	this->addChild(bgPause);

	auto itemRestart = MenuItemImage::create("UI/gameover/button_restart_0.png", 
		"UI/gameover/button_restart_1.png", 
		CC_CALLBACK_1(VictoryLayer::menuItemRestartCallback, this));
	auto itemChooseStage = MenuItemImage::create("UI/gameover/button_level_0.png", 
		"UI/gameover/button_level_1.png", 
		CC_CALLBACK_1(VictoryLayer::menuItemChooseStageCallback, this));
	auto itemHomePage = MenuItemImage::create("UI/gameover/button_menu_0.png", 
		"UI/gameover/button_menu_1.png", 
		CC_CALLBACK_1(VictoryLayer::menuItemHomePageCallback, this));
	auto itemNextLevel = MenuItemImage::create("UI/gameover/button_nextlv_0.png",
		"UI/gameover/button_nextlv_1.png",
		CC_CALLBACK_1(VictoryLayer::menuItemNextLevelCallback, this));
	auto menuPause = Menu::create(itemRestart, itemChooseStage, itemHomePage, itemNextLevel, NULL);
	menuPause->alignItemsHorizontally();
	menuPause->setPosition(Vec2(this->getPosition().x, 
		this->getPosition().y - bgPause->getContentSize().height / 3 - 15));

	this->addChild(menuPause);
}

void VictoryLayer::menuItemRestartCallback(Ref * pSender)
{
	Director::getInstance()->resume();
	log("Restart");
	Director::getInstance()->resume();
	Director::getInstance()->replaceScene(Game::createScene());
}
void VictoryLayer::menuItemChooseStageCallback(Ref * pSender)
{
	Director::getInstance()->resume();
	log("ChooseStage");
	Director::getInstance()->resume();
	Director::getInstance()->replaceScene(ChoseLevel::createScene());
}
void VictoryLayer::menuItemHomePageCallback(Ref * pSender)
{
	Director::getInstance()->resume();
	log("HomePage");
	Director::getInstance()->resume();
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}
void VictoryLayer::menuItemNextLevelCallback(Ref * pSender)
{
	Director::getInstance()->resume();
	++Game::levelNum;
	Director::getInstance()->resume();
	Director::getInstance()->replaceScene(Game::createScene());
}