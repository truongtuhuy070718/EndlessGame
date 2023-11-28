#ifndef __START_SCENE_H__
#define __START_SCENE_H__
#include "Road/Road.h"
#include "cocos2d.h"
#include "Item/Item.h"
#include <vector>
#include "Car/Car.h"

class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void update(float ft) override;
    ItemType getRandomItemType();
    std::vector<Road*> roads;
    Car* car;
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);

    
private: 
    void startGame();

    

    bool gameStarted = false;
    float elapsedTime = 1;
};

#endif // __START_SCENE_H__
