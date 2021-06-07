#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Cannon
{
public:
	Sprite * Cannon_Image;

	Sprite * Bumb;

	Point point;

	Layer * Layer_Back3;

	int StartDistance;

	int EndDistance;

	int PowerVariable;

	int Power;

	int Counter;

	double MoveX;

	double MoveY;

	double MoveXFrame;

	double MoveYFrame;

	float Degree;

	void SetCannonPower(Point TouchBeganPosition, Point TouchEndedPosition);

	void SetCannonAngle(Point TouchPosition, Point CannonPosition);

	void ShootCannon();

	bool ShootingCannon();

	MoveBy* Shoot;

	void Cn_In();

	void Bumb_reset();
};