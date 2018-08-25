#pragma once
#include<cocos2d.h>
#include"cocos-ext.h"
USING_NS_CC_EXT;
using namespace cocos2d::extension;
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#ifndef _SETTING_SCENE_H_
#define _SETTING_SCENE_H_

class Setting :public cocos2d::Layer
{
public:
	static cocos2d::Scene * createScene();
	bool init();
	void menuSoundToggleCallback(Ref *pSender);
	void menuMusicToggleCallback(Ref *pSender);
	void menuOkCallback(Ref *pSender);
	void musicChanged(Ref *sender, Control::EventType);
	void soundChanged(Ref *sender, Control::EventType);

	CREATE_FUNC(Setting);

};
#endif