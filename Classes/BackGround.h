#pragma once
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class BackGround : public Layer
{
public:
	Sprite * Back;
	Sprite * Endline;
	Sprite * Heart[5];

	Sprite * Start;
	
	Layer * Layer_Back;
	Layer * Layer_Start;

	void Bg_In();
	void MainBack();
    
    CREATE_FUNC(BackGround);
};
