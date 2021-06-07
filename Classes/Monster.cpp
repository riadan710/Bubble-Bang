#include "Monster.h"

bool Monster::init()
{
	if (Layer::init() == false)
		return false;

	return true;
}

Monster::Monster()
{
	Monster_Layer = Layer::create();
}

void Monster::Set_Normal()
{
	int randW = CCRANDOM_0_1() * 900 + 90;
	Sprite* spr = Sprite::create("NormalMon.png");
	spr->setPosition(Point(randW, 1780));
	spr->setScale(0.3);
	spr->setScaleY(0.35);
	Monster_Layer->addChild(spr);
	Normal.pushBack(spr);
	Moving = Sequence::create(MoveBy::create(10.0, Point(0, -1250)),
		CallFuncN::create(CC_CALLBACK_1(Monster::Reset_Normal, this)), NULL);
	spr->runAction(Moving);
}

void Monster::Reset_Normal(Ref* sender)
{
	Normal.eraseObject((Sprite*)sender);
	Monster_Layer->removeChild((Sprite*)sender);
}

void Monster::Reset_Normal_Hit(Ref* sender)
{
	Normal.eraseObject((Sprite*)sender);
	Monster_Layer->removeChild((Sprite*)sender);
}

void Monster::Set_Speed()
{
	int randW = CCRANDOM_0_1() * 900 + 90;
	Sprite * spr = Sprite::create("SpeedMon.png");
	spr->setPosition(Point(randW, 1780));
	spr->setScale(0.3);
	Speed.pushBack(spr);
	Monster_Layer->addChild(spr);
	Moving = Sequence::create(MoveBy::create(8.0, Point(0, -1250)),
		CallFuncN::create(CC_CALLBACK_1(Monster::Reset_Speed, this)), NULL);
	spr->runAction(Moving);

}

void Monster::Reset_Speed(Ref* sender)
{
	Speed.eraseObject((Sprite*)sender);
	Monster_Layer->removeChild((Sprite*)sender);
}

void Monster::Set_Fat()
{
	srand(GetTickCount());
	int randW7 = CCRANDOM_0_1() * 900 + 90;
	Sprite * spr = Sprite::create("FatMon.png");
	spr->setPosition(Point(randW7, 1780));
	spr->setScale(0.3);
	Fat.pushBack(spr);
	Monster_Layer->addChild(spr);
	Moving = Sequence::create(MoveBy::create(13.0, Point(0, -1250)),CallFuncN::create(CC_CALLBACK_1(Monster::Reset_Fat, this)), NULL);
	spr->runAction(Moving);
}

void Monster::Reset_Fat(Ref* sender)
{
	Fat.eraseObject((Sprite*)sender);
	Monster_Layer->removeChild((Sprite*)sender);
}

void Monster::crash()
{
	for(int i=0 ; i<Normal.size() ; i++)
	{
		auto spr = (Sprite*)Normal.at(i);
		if (spr->getBoundingBox().intersectsRect(cannon->Bumb->getBoundingBox()))
		{
			cannon->Bumb->setPosition(cannon->point);
			cannon->Counter = 100;
			Normal.eraseObject(spr);	
			Monster_Layer->removeChild(spr);
		}
	}
	for (int i = 0; i < Speed.size(); i++)
	{
		auto spr = (Sprite*)Speed.at(i);
		if (spr->getBoundingBox().intersectsRect(cannon->Bumb->getBoundingBox()))
		{
			cannon->Bumb->setPosition(cannon->point);
			cannon->Counter = 100;
			Speed.eraseObject(spr);
			Monster_Layer->removeChild(spr);
		}
	}
	for (int i = 0; i < Fat.size(); i++)
	{
		auto spr = (Sprite*)Fat.at(i);
		if (spr->getBoundingBox().intersectsRect(cannon->Bumb->getBoundingBox()))
		{
			cannon->Bumb->setPosition(cannon->point);
			cannon->Counter = 100;
			Fat.eraseObject(spr);
			Monster_Layer->removeChild(spr);
		}
	}
}