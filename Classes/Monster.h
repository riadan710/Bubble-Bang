#pragma once
#include "cocos2d.h"
#include "Cannon.h"

USING_NS_CC;


class Monster : public Layer
{
public:
	virtual bool init();

	Monster();

	Vector<Sprite *> Normal;
	Vector<Sprite *> Speed;
	Vector<Sprite *> Fat;
	
	Layer * Monster_Layer;

	Action * Moving;

	void Set_Normal();

	void Reset_Normal(Ref * sender); //발사 후 (빗나갔을때)
	void Reset_Normal_Hit(Ref * sender); //충돌시

	void Set_Speed();

	void Reset_Speed(Ref * sender);
	void Reset_Speed_Hit(Ref * sender);

	void Set_Fat();

	void Reset_Fat(Ref * sender);
	void Reset_Fat_Hit(Ref * sender);
	
	Cannon* cannon;

	void crash();

    CREATE_FUNC(Monster);
};
