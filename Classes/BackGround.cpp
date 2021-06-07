#include "BackGround.h"

void BackGround::Bg_In()
{
	Layer_Back = Layer::create();
	Back = Sprite::create("back.png");
	Back->setPosition(Point(1080 / 2, 1920 / 2));

	Endline = Sprite::create("endline.png");
	Endline->setPosition(Point(540, 470));
	Endline->setScale(2.0);

	for (int i = 0; i < 5; i++)
	{
		Heart[i] = Sprite::create("heart.png");
		Heart[i]->setPosition(Point(720 + (75*i), 380));
		Heart[i]->setScale(0.15);
	}

	Layer_Back->addChild(Back);
	Layer_Back->addChild(Endline);
	for (int i = 0; i < 5; i++)
		Layer_Back->addChild(Heart[i]);
}

void BackGround::MainBack()
{
	Layer_Start = Layer::create();
	Start = Sprite::create("start.png");
	Start->setPosition(1080 / 2, 1920 / 2);

	Layer_Start->addChild(Start);
}