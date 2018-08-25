#include "PickupBase.h"
#include "GameScene.h"
#include <cstring>

PickupBase * PickupBase::createWithType(PickupTypes type)
{
	auto item = new PickupBase();
	std::string path;
	switch (type)
	{
	case Gold:
		path = GOLDPATH; break;
	case Bulletscatter:
		path = BulletscatterPath; break;
	}
	if (item && item->initWithFile(path))
	{
		item->autorelease();
	}
	auto body = PhysicsBody::createEdgeBox(item->getContentSize());
	body->setCategoryBitmask(0x02);
	body->setContactTestBitmask(0x01);
	item->setPhysicsBody(body);
	item->setTag(6);
	return item;
}

PickupBase * PickupBase::createWithImage(const char * path)
{
	auto item = new PickupBase();
	if (item && item->initWithFile(path))
	{
		item->autorelease();
	}
	auto body = PhysicsBody::createEdgeBox(item->getContentSize());
	body->setCategoryBitmask(0x02);
	body->setContactTestBitmask(0x01);
	item->setPhysicsBody(body);
	item->setTag(6);
	return item;
}

void PickupBase::isContact(OurTank * player)
{
	log("pick up");
	log("Type: %d", this->getPickupType());
	switch (this->getPickupType())
	{
	case Bulletscatter:
		player->setHP(player->getHP() + 1);
		player->setWeaponType(WEAPON_3);
		log("HP: %d", player->getHP());
		this->removeFromParent();
		break;

	}

}