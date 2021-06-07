#include "cocos2d.h"
USING_NS_CC;

class Life : public Layer
{
public:
	Sprite * Life_Image[3];

	Layer * Layer_Back2;

	void Life_In();

	CREATE_FUNC(Life);
};