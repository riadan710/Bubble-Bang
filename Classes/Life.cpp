#include "Life.h"

void Life::Life_In()
{
	Layer_Back2 = Layer::create();
	for (int i = 0; i < 3; i++)
	{
		Life_Image[i] = Sprite::create("heart.png");
		Life_Image[i]->setPosition(Point(1000-i*100, 100));
		Life_Image[i]->setAnchorPoint(Point(0.5, 0.5));
		Life_Image[i]->setScale(0.2);
		Layer_Back2->addChild(Life_Image[i]);
	}
}