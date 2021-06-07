#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}


bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	background = new BackGround();
	background->MainBack();
	this->addChild(background->Layer_Start);

	background->Bg_In();

	cannon = new Cannon();
	cannon->Cn_In();
	monster = new Monster();
	monster->cannon = cannon;
	this->addChild(background->Layer_Back);
	this->addChild(cannon->Layer_Back3);
	this->addChild(monster->Monster_Layer);
	auto listener = EventListenerTouchOneByOne::create();

	//Score_Point->setString(CCString::createWithFormat("점수: %d", score)->getCString());

	this->schedule(schedule_selector(HelloWorld::Set_Normal), 3 + rand()%4);
	this->schedule(schedule_selector(HelloWorld::Set_Speed), 3 + rand() % 4);
	this->schedule(schedule_selector(HelloWorld::Set_Fat), 3 + rand() % 4);

	this->schedule(schedule_selector(HelloWorld::crash), 0.1);
	//this->schedule(schedule_selector(HelloWorld::Score_check), 0.1);

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	cannon->Bumb->setPosition(cannon->point);
	cannon->SetCannonAngle(touch->getLocation(), cannon->point);
	TouchBeganPosition = touch->getLocation();
	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	cannon->SetCannonAngle(touch->getLocation(), cannon->point);
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	TouchEndedPosition = touch->getLocation();
	cannon->SetCannonPower(TouchBeganPosition, TouchEndedPosition);
	cannon->ShootCannon();
	schedule(schedule_selector(HelloWorld::ShootCount), 0.0075f);
}

void HelloWorld::ShootCount(float dt)
{
	if (!cannon->ShootingCannon())
	{
		unschedule(schedule_selector(HelloWorld::ShootCount));

	}
}

void  HelloWorld::Set_Normal(float dt)
{
	monster->Set_Normal();
}

void  HelloWorld::Set_Speed(float dt)
{
	monster->Set_Speed();
}

void  HelloWorld::Set_Fat(float dt)
{
	monster->Set_Fat();
}

void HelloWorld::crash(float dt)
{
	monster->crash();
}

void HelloWorld::Score_check(float dt)
{
	Score_Point->setString(CCString::createWithFormat("점수: %d", score)->getCString());
}