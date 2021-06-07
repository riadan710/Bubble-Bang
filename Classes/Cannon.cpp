#include "Cannon.h"

void Cannon::Cn_In()
{
	Layer_Back3 = Layer::create();

	Cannon_Image = Sprite::create("cannon.png");

	Counter = 1;

	Cannon_Image->setPosition(Point(540, 280));

	Cannon_Image->setScale(0.4);

	point = Point(540, 280);

	Bumb = Sprite::create("ball.png");

	Bumb->setPosition(Point(540, 280));

	Bumb->setScale(0.2);

	Layer_Back3->addChild(Bumb);

	Layer_Back3->addChild(Cannon_Image);	
}

void Cannon::SetCannonPower(Point TouchBeganPosition, Point TouchEndedPosition)
{
	StartDistance = sqrt(pow((point.x - TouchBeganPosition.x), 2) + pow((point.y - TouchBeganPosition.y), 2)); // 시작점과 대포 중심까지의 거리

	EndDistance = sqrt(pow((point.x - TouchEndedPosition.x), 2) + pow((point.y - TouchEndedPosition.y), 2)); // 끝점과 대포 중심까지의 거리

	PowerVariable = EndDistance - StartDistance; //파워 비례상수 설정 
}

void Cannon::SetCannonAngle(Point TouchPosition, Point CannonPosition)
{
	if (CannonPosition.y > TouchPosition.y)
	{
		Degree = atan2f((double)CannonPosition.y - TouchPosition.y, (double)CannonPosition.x - TouchPosition.x) * 180 / 3.1415f;
	}
	if (Degree < 30)
	{
		Degree = 30;
	}
	else if (Degree > 150)
	{
		Degree = 150;
	}
	Cannon_Image->setRotation(90 - Degree);
}

void Cannon::ShootCannon()
{
	if (PowerVariable > 0)
	{
		Power = PowerVariable * 5;
		if (90 - Degree > 0)
		{
			MoveX = Power * cos((Degree) * 3.1416 / 180);
			MoveY = Power * sin((Degree) * 3.1416 / 180);
		}
		else
		{
			MoveX = Power * cos((Degree) * 3.1416 / 180);
			MoveY = Power * sin((Degree) * 3.1416 / 180);
		}
		MoveXFrame = MoveX / 100;
		MoveYFrame = MoveY / 100;
	}
}

bool Cannon::ShootingCannon()
{
	if (Bumb->getBoundingBox().getMinX() < 0 || Bumb->getBoundingBox().getMaxX() > 1080)
	{
		MoveXFrame = -MoveXFrame;
	}
	if (Bumb->getBoundingBox().getMaxY() > 1920 || Bumb->getBoundingBox().getMinY() < 0)
	{
		MoveYFrame = -MoveYFrame;
	}
	Bumb->setPosition(Bumb->getPosition().x + MoveXFrame * (100 - Counter) / 50, Bumb->getPosition().y + MoveYFrame * (100 - Counter) / 50);
	//Bumb->setPosition(Bumb->getPosition().x + MoveXFrame, Bumb->getPosition().y + MoveYFrame);
	Counter++;
	if (Counter == 101)
	{
		Counter = 1;
		return false;
	}
	return true;
}

void Cannon::Bumb_reset()
{
	Bumb->setPosition(540, 280);
}