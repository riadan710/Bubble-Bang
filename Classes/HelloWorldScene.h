#pragma once
#include "cocos2d.h"
#include "BackGround.h"
#include "Cannon.h"
#include "Monster.h"
#include "math.h"

class HelloWorld : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	BackGround * background;
	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event* event);

	virtual void onTouchMoved(Touch* touch, Event* event);

	virtual void onTouchEnded(Touch* touch, Event* event);

	void ShootCount(float dt);

	Point TouchBeganPosition;

	Point TouchEndedPosition;

	int StartDistance;

	int EndDistance;

	int PowerVariable;

	int Power;

	double MoveX;

	double MoveY;

	float Degree;

	Cannon * cannon;

	Monster * monster;

	void initData();

	void Set_Normal(float dt);
	void Set_Speed(float dt);
	void Set_Fat(float dt);
	void crash(float dt);

	int score = 0;
	Label * Score_Point;
	void Score_check(float dt);

	DelayTime StartView;

    CREATE_FUNC(HelloWorld);
};
