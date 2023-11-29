
#ifndef __DEFINEBITMASK_H__
#define __DEFINEBITMASK_H__

#include <Vector>
#include "cocos2d.h"

class DefineBitmask : public cocos2d::Sprite
{
public:
	static const int NON = 0;
	static const int GOLD = 1;
	static const int BOMB = 2;
	static const int CAR = 3;
};

#endif // __DEFINEBITMASK_H__
