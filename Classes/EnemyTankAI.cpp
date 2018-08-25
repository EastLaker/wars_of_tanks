#include "EnemyTankAI.h"
#include "Enemy.h"


void EnemyAI::initEnemyAIWithTank(Enemy * tank)

{

	mTank = tank;
	mTileMapInfo = TMXMapInfo::create("map/map.tmx");
	//mTileMapInfo = (TMXTiledMap *)(tank->getParent()->getChildByTag(1))

	mEnemyTanks = CCArray::createWithCapacity(4);

	mEnemyTanks->retain();

	//��ʼ�����ֵص�

	CCSize mapSize = mTileMapInfo->getMapSize();

	CCSize tileSize = mTileMapInfo->getTileSize();

	bornPoint[0] = ccp(tileSize.width, mapSize.height - tileSize.height);

	bornPoint[1] = ccp(mapSize.width / 2, mapSize.height - tileSize.height);

	bornPoint[2] = ccp(mapSize.width - tileSize.width, mapSize.height - tileSize.height);

}


EnemyAI* EnemyAI::createEnemyAIWithTank(Enemy * tank)
{
	EnemyAI* enemyTank = new EnemyAI();
	enemyTank->initEnemyAIWithTank(tank);
	return enemyTank;
}


void EnemyAI::addTank(float delta)

{

	static float deltaTimes = 0.0f;

	deltaTimes += delta;

	if (deltaTimes >= 2.0f)

	{

		deltaTimes = 0.0f;

		int count = mEnemyTanks->count();

		if (count < 3)	//�ȴӹ̶�λ���������̹��

		{

			Enemy * enemyTank = Enemy::createWithEnemyTypes(EnemyTypeEnemy1);

			enemyTank->setPosition(bornPoint[count]);

			enemyTank->setRotation(180.0f);

			mEnemyTanks->addObject(enemyTank);

		}

		else if (count == 3)	//���ĸ�̹��������

		{

			int tankTypeIndex = (int)(CCRANDOM_0_1() * 4) % 3;

			Enemy * enemyTank = Enemy::createWithEnemyTypes(EnemyTypeEnemy1);

			enemyTank->setPosition(bornPoint[tankTypeIndex]);

			enemyTank->setRotation(180.0f);

			mEnemyTanks->addObject(enemyTank);

		}

	}

}


void EnemyAI::tankAction(float delta)
{
	CCObject* pObj;

	CCARRAY_FOREACH(mEnemyTanks, pObj)
	{

		Enemy * tank = (Enemy *)pObj;

		//̹���Զ��ƶ�������ǽ���Զ�������

		int Rotation = tank->getRotation();

		tank->runAction(RotateBy::create(2, 90));

		//if (!tank->command((enumOrder)(Rotation / 90 + 1)))
		//{
		//	int n = (int)(CCRANDOM_0_1() * 5) % 5;

		//	if (n != 0)
		//		tank->command((enumOrder)n);
		//}

		//ÿ��һ�뿪һ�λ�
		//tank->setBulletDelta(tank->getBulletDelta() + delta);
		//if (tank->getBulletDelta() > 0.5)
		//{
		//	//���������ӵ��ڷ����У������ʱ
		//	if (tank->command(cmdFire))
		//	{
		//		tank->setBulletDelta(0.0);
		//	}
		//}
	}
}
void EnemyAI::update(float delta)
{
	//̹�˲���4��������̹��
	addTank(delta);

	//̹����Ϊ����
	tankAction(delta);
}

