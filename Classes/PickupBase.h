#pragma once
#include "cocos2d.h"
#include "OurTank.h"

using namespace cocos2d;

#define GOLDPATH "map/stageGold1.png"
#define BulletscatterPath "map/3Bullets.png"

typedef enum
{
	Gold,
	Bulletscatter,
	Weapon_1,
	Weapon_2
}PickupTypes;

class PickupBase : public Sprite
{
	CC_SYNTHESIZE(PickupTypes, pickupType, PickupType);
public:
	static PickupBase * createWithImage(const char *);
	static PickupBase * createWithType(PickupTypes );
	virtual void isContact(OurTank *);
};