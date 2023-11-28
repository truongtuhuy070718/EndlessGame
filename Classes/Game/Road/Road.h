#ifndef __Road__
#define __Road__
#include <Vector>
#include "cocos2d.h"

class Road : public cocos2d::Sprite
{
public:
    static Road* create();
    Sprite* roadLand1;
    Sprite* roadLand2;
    Sprite* roadLand3;
    virtual bool init() ;
protected:
    void update(float dt) override;

    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    //CREATE_FUNC(Road);
};

#endif // __Road__
