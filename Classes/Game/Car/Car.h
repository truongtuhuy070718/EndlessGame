#ifndef __Car_H__
#define __Car_H__
#include <Vector>
#include "cocos2d.h"

class Car : public cocos2d::Sprite
{
public:
    static Car* createCar(const std::string& filename);
    virtual bool init() ;
protected:
    

    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    //CREATE_FUNC(Road);
};

#endif // __Car_H__
